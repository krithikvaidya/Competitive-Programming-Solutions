
        cout<<left<<nouppercase;
        long long a = (long long)A;
        cout<<hex<<showbase<<a<<dec<<"\n";
        bool flag;
        if(B < 0)
            flag = true;
        else
            flag = false;

        cout<<setw(15)<<right<<showpos<<setprecision(2)<<setfill('_')<<fixed<<B<<"\n";

        cout<<noshowpos<<left<<scientific<<uppercase<<setprecision(9)<<C<<"\n";

