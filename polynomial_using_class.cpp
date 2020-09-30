/* Dev C++ */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class poly{
    public:
    poly(double c, int p){//constructor takin coefficient and power as arguments
        if(c!=0) v.push_back(make_pair(p,c));
    }
    
    void print(){//print member function, prints a polynomial
        sort(v.begin(),v.end());
        int l=v.size()-1,flag=0;
        if(l==-1) cout<<0;
        for(int i=l;i>=0;i--){
            if(v[i].second==0){
                if((i==0 && flag==0)){
                    cout<<0;
                }
                continue;
            }
            flag=1;
            if(v[i].second<0) cout<<" - ";
            else{
                if(i!=l) cout<<" + ";   
            }
            if(abs(v[i].second)!=1) cout<<abs(v[i].second);
            else if(abs(v[i].second)==1 && v[i].first==0) cout<<abs(v[i].second);
            if(v[i].first!=0){ cout<<"x"; if(v[i].first!=1) cout<<"^"<<v[i].first; }
        }
        cout<<endl;
    }
    
    poly operator +(poly p){//overloading + operator using merge algo
        poly p4(0,0);
        sort(p.v.begin(),p.v.end());
        int pi=p.v.size()-1,i=v.size()-1;
        while(pi>=0 && i>=0){
            if(v[i].first == p.v[pi].first){
                if(v[i].second != -p.v[pi].second)
                    p4.v.push_back(make_pair(v[i].first,v[i].second+p.v[pi].second));
                i--; pi--;
            }
            else if(v[i].first>p.v[pi].first){
                p4.v.push_back(make_pair(v[i].first,v[i].second));
                i--;
            }
            else{
                p4.v.push_back(make_pair(p.v[pi].first,p.v[pi].second));
                pi--;
            }
        }
        while(pi>=0){
            p4.v.push_back(make_pair(p.v[pi].first,p.v[pi].second));
            pi--;
        }
        while(i>=0){
            p4.v.push_back(make_pair(v[i].first,v[i].second));
            i--;
        }
            
        sort(p4.v.begin(),p4.v.end());
        return p4;
    }
    
    poly operator -(poly p){//overloading - operator using merge algo
        poly p4(0,0);
        sort(p.v.begin(),p.v.end());
        int pi=p.v.size()-1,i=v.size()-1;
        while(pi>=0 && i>=0){
            if(v[i].first == p.v[pi].first){
                if(v[i].second != p.v[pi].second)
                    p4.v.push_back(make_pair(v[i].first,v[i].second-p.v[pi].second));
                i--; pi--;
            }
            else if(v[i].first>p.v[pi].first){
                p4.v.push_back(make_pair(v[i].first,v[i].second));
                i--;
            }
            else{
                p4.v.push_back(make_pair(p.v[pi].first,-p.v[pi].second));
                pi--;
            }
        }
        while(pi>=0){
            p4.v.push_back(make_pair(p.v[pi].first,-p.v[pi].second));
            pi--;
        }
        while(i>=0){
            p4.v.push_back(make_pair(v[i].first,v[i].second));
            i--;
        }
            
        sort(p4.v.begin(),p4.v.end());
        return p4;
    }
    
    void operator +=(poly p){//overloading += operator using merge algo
        sort(p.v.begin(),p.v.end());
        int pi=p.v.size()-1,i=v.size()-1;
        while(pi>=0 && i>=0){
            if(v[i].first == p.v[pi].first){
                v[i].second+=p.v[pi].second;
                if(v[i].second==0) v.erase(v.begin()+i);
                i--; pi--;
            }
            else if(v[i].first>p.v[pi].first){
                i--;
            }
            else{
                v.push_back(make_pair(p.v[pi].first,p.v[pi].second));
                pi--;
            }
        }
        while(pi>=0){
            v.push_back(make_pair(p.v[pi].first,p.v[pi].second));
            pi--;
        }
        sort(v.begin(),v.end());
    }
    
    void operator -=(poly p){//overloading -= operator using merge algo
        sort(p.v.begin(),p.v.end());
        int pi=p.v.size()-1,i=v.size()-1;
        while(pi>=0 && i>=0){
            if(v[i].first == p.v[pi].first){
                v[i].second-=p.v[pi].second;
                if(v[i].second==0) v.erase(v.begin()+i);
                i--; pi--;
            }
            else if(v[i].first>p.v[pi].first){
                i--;
            }
            else{
                v.push_back(make_pair(p.v[pi].first,-p.v[pi].second));
                pi--;
            }
        }
        while(pi>=0){
            v.push_back(make_pair(p.v[pi].first,-p.v[pi].second));
            pi--;
        }
        sort(v.begin(),v.end());
    }
    
    void operator *=(double k){//overloading *= operator by multiplying all the coefficients with constant k
        for(int i=v.size()-1;i>=0;i--){
            v[i].second*=k;
        }
    }
    
    double at(double d){//'at' member function that returns the value of the polynomial at x=d
        double ans=0;
        for(int i=v.size()-1;i>=0;i--)
            ans+=((v[i].second)*pow(d,v[i].first));
        return ans;
    }
    
    private :
    vector< pair<int,double> > v;//vector of pairs that stores power,coefficient in first,second resp.
};

int main() {
    int n,p;
    double c;
label1:
    cout<<"Please supply a polynomial first by entering the no. of terms : ";
    cin>>n;
    if(n<=0){ cout<<"\nNo. of terms must be positive integer\n"<<endl; goto label1; }
    cout<<"Please enter "<<n<<" pair(s) of coeff. and exponents :"<<endl;
    cin>>c>>p;
    poly p1(c,p);
    n--;
    while(n--){
        cin>>c>>p;
        poly p2(c,p);
        p1+=p2;
    }
    cout<<"\nEntered polynomail is : ";
    p1.print();
    cout<<endl;
    while(1){
    label2:
        cout<<"\nMenu"<<endl;
        cout<<"1.Concatenate with addition             : +     operation"<<endl;
        cout<<"2.Concatenate with subtraction          : -     operation"<<endl;
        cout<<"3.Add a polynomial to this polynomial   : +=    operation"<<endl;
        cout<<"4.Sub a polynomial from this polynomial : -=    operation"<<endl;
        cout<<"5.Mult this polynomial with a constant  : *=    operation"<<endl;
        cout<<"6.Find value of this polynomial         : .at() operation"<<endl;
        cout<<"7.Exit"<<endl;
        cout<<"\nEnter a choice : ";
        int m; cin>>m;
        cout<<endl;
        switch(m){//switch-case for 'menu'
            case 1:
                {
                    int no,po;
                    double co;
                    cout<<"Please enter the no. of terms in the new polynomial : ";
                    cin>>no;
                    if(no<=0){ cout<<"\nNo. of terms must be positive integer\n"<<endl; goto label2; }
                    cout<<"Please enter "<<no<<" pair(s) of coeff. and exponents :"<<endl;
                    cin>>co>>po;
                    poly p0(co,po);
                    no--;
                    while(no--){ cin>>co>>po; poly p3(co,po); p0+=p3; }
                    cout<<"\nNewly entered polynomial :\n";
                    p0.print();
                    cout<<"\nConcatenated polynomial :\n";
                    poly p4(0,0);
                    p4=p1+p0;
                    p4.print();
                    cout<<endl;
                    break;
                }
            case 2:
                 {
                    int no,po;
                    double co;
                    cout<<"Please enter the no. of terms in the new polynomial : ";
                    cin>>no;
                    if(no<=0){ cout<<"\nNo. of terms must be positive integer\n"<<endl; goto label2; }
                    cout<<"Please enter "<<no<<" pair(s) of coeff. and exponents :"<<endl;
                    cin>>co>>po;
                    poly p0(co,po);
                    no--;
                    while(no--){ cin>>co>>po; poly p3(co,po); p0+=p3; }
                    cout<<"\nNewly entered polynomial :\n";
                    p0.print();
                    cout<<"\nConcatenated polynomial :\n";
                    poly p4(0,0);
                    p4=p1-p0;
                    p4.print();
                    cout<<endl;
                    break;
                }
            case 3:
                {
                    int no,po;
                    double co;
                    cout<<"Please enter the no. of terms in the new polynomial : ";
                    cin>>no;
                    if(no<=0){ cout<<"\nNo. of terms must be positive integer\n"<<endl; goto label2; }
                    cout<<"Please enter "<<no<<" pair(s) of coeff. and exponents :"<<endl;
                    cin>>co>>po;
                    poly p0(co,po);
                    no--;
                    while(no--){ cin>>co>>po; poly p3(co,po); p0+=p3; }
                    cout<<"\nNewly entered polynomial :\n";
                    p0.print();
                    p1+=p0;
                    cout<<"\nResultant polynomial :\n";
                    p1.print();
                    cout<<endl;
                    break;
                }
            case 4:
                {
                    int no,po;
                    double co;
                    cout<<"Please enter the no. of terms in the new polynomial : ";
                    cin>>no;
                    if(no<=0){ cout<<"\nNo. of terms must be positive integer\n"<<endl; goto label2; }
                    cout<<"Please enter "<<no<<" pair(s) of coeff. and exponents :"<<endl;
                    cin>>co>>po;
                    poly p0(co,po);
                    no--;
                    while(no--){ cin>>co>>po; poly p3(co,po); p0+=p3; }
                    cout<<"\nNewly entered polynomial :\n";
                    p0.print();
                    p1-=p0;
                    cout<<"\nResultant polynomial :\n";
                    p1.print();
                    cout<<endl;
                    break;
                }
            case 5:
                {   
                    double k;
                    cout<<"Please enter a constant : ";
                    cin>>k;
                    p1*=k;
                    cout<<"\nResultant polynomial :\n";
                    p1.print();
                    break;
                }
            case 6:
                {   
                    double d;
                    cout<<"Enter the value of 'x' to calculate poly(x) : ";
                    cin>>d;
                    cout<<"\nValue of the polynomial at x = "<<d<<" is ";
                    cout<<p1.at(d)<<endl;
                    break;
                }
            case 7:
                exit(1);
            default:
                cout<<"Please enter a valid choice!"<<endl;
        }
    }
}
