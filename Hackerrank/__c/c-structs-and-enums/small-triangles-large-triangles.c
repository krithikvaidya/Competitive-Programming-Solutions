
void sort_by_area(triangle* tr, int n) 
{
    int min, i, j, pos, temp;
    float p, A;
    
    for(i=0;i<n;i++)
    {
        pos = i;
        p = tr[i].a + tr[i].b + tr[i].c;
        p/=2.0;
        
        A = sqrt(p * (p - tr[i].a) * (p - tr[i].b) * (p - tr[i].c) * 1.0);
    
        for(j = i; j < n; j++)
        {
            p = tr[j].a + tr[j].b + tr[j].c;
            p/=2.0;
            if(sqrt(p * (p - tr[j].a) * (p - tr[j].b) * (p - tr[j].c) * 1.0) < A)
            {
                pos = j;
                A = sqrt(p * (p - tr[j].a) * (p - tr[j].b) * (p - tr[j].c) * 1.0);
                
            }
        }
            temp = tr[i].a;
            tr[i].a = tr[pos].a;
            tr[pos].a = temp;
            
            temp = tr[i].b;
            tr[i].b = tr[pos].b;
            tr[pos].b = temp;
            
            
            temp = tr[i].c;
            tr[i].c = tr[pos].c;
            tr[pos].c = temp;
        
    }
}
