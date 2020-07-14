#include "test_framework/generic_test.h"
#include "test_framework/serialization_traits.h"
#include "test_framework/test_failure.h"

using std::length_error;
using namespace std;

class Queue {


 private:
  
  int front;
  int back;
  int capacity;
  int size;
  int* arr;

 public:
  
  Queue(size_t capacity) {
    arr = new int[capacity]; 
    front = -1;
    back = 0;
    capacity = capacity;
    size = 0;
  }

  void Enqueue(int x) {
    
    cout << "\nEnqueue: " << x << "\nSize: " << size << "\n";
    if (back == front)
    {
      throw length_error("queue is full");
    }

    if (back == capacity)
    {
      back = 0;
      Enqueue (x);
      return;
    }

    if (front == -1)
      front++;

    arr[back] = x;
    back++;
    size++;

    return;
  }


  int Dequeue() {
    
    cout << "\nDequeue." << "\nSize: " << size << "\n";
    if (front == -1)
      throw length_error("queue is empty");

    int toret = arr[front];

    size--;
    front++;

    if (back == front)
    {
      front = -1;
      back = 0;
    }

    if (front == capacity)
      front = 0;

    return toret;
  }

  int Size() const {

    cout << "\nSize: " << size << "\n";
    return size;
    
  }
};
struct QueueOp {
  enum class Operation { kConstruct, kDequeue, kEnqueue, kSize } op;
  int argument;

  QueueOp(const std::string& op_string, int arg) : argument(arg) {
    if (op_string == "Queue") {
      op = Operation::kConstruct;
    } else if (op_string == "dequeue") {
      op = Operation::kDequeue;
    } else if (op_string == "enqueue") {
      op = Operation::kEnqueue;
    } else if (op_string == "size") {
      op = Operation::kSize;
    } else {
      throw std::runtime_error("Unsupported queue operation: " + op_string);
    }
  }

  void execute(Queue& q) const {
    switch (op) {
      case Operation::kConstruct:
        // Hack to bypass deleted assign operator
        q.~Queue();
        new (&q) Queue(argument);
        break;
      case Operation::kDequeue: {
        int result = q.Dequeue();
        if (result != argument) {
          throw TestFailure("Dequeue: expected " + std::to_string(argument) +
                            ", got " + std::to_string(result));
        }
      } break;
      case Operation::kEnqueue:
        q.Enqueue(argument);
        break;
      case Operation::kSize: {
        int s = q.Size();
        if (s != argument) {
          throw TestFailure("Size: expected " + std::to_string(argument) +
                            ", got " + std::to_string(s));
        }
      } break;
    }
  }
};

namespace test_framework {
template <>
struct SerializationTrait<QueueOp> : UserSerTrait<QueueOp, std::string, int> {};
}  // namespace test_framework

void QueueTester(const std::vector<QueueOp>& ops) {
  Queue q(0);
  for (auto& op : ops) {
    op.execute(q);
  }
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"ops"};
  return GenericTestMain(args, "circular_queue.cc", "circular_queue.tsv",
                         &QueueTester, DefaultComparator{}, param_names);
}
