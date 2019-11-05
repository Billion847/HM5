#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;
class ReportParser
{
public:
    ReportParser(int numStudents, int numInfos);
    ~ReportParser();
    void readReport();
    void writeStructuredReport(int sortOption);
    // Add your own functions and variables here
private:
    // Add your own functions and variables here
    string **student;
    int r_numStudents;
    int r_numInfos;
    int r_length=0;
    int * max;
};

ReportParser::ReportParser(int numStudents, int numInfos) 
{
    // Your code here
    int i=0;
    int j=0;
    student=new string *[numStudents];
    for(i=0;i<numStudents;i++){
        student[i]=new string [numInfos];
    }
    r_numStudents=numStudents;
    r_numInfos=numInfos;

    
} 

ReportParser::~ReportParser() 
{
    // Your code here
    int i;
    for(i=0;i<r_numStudents;i++){
        delete [] student[i];
    }
    delete [] student;
}


void ReportParser::readReport()
{
    // Your code here
    int j,p;
    for(j=0;j<r_numStudents;j++){
        for(p=0;p<r_numInfos;p++){
            cin>>student[j][p];
        }
    }
}

void ReportParser::writeStructuredReport(int sortOption)
{
    // Your code here
    int j,p;
    int q3=0;
    int *max;
    max=new int [r_numInfos];
    string *buf;
    for(j=0;j<r_numStudents-1;j++){
        for(p=0;p<r_numStudents-1;p++){
            if(student[p+1][sortOption]<student[p][sortOption]){
               buf=student[p];
               student[p]=student[p+1];
               student[p+1]=buf;
            }
        }
    }
    for(int u=0;u<r_numInfos;u++){
        max[u]=0;
    }

    for(int i=0;i<r_numInfos;i++){
        for(int l=0;l<r_numStudents;l++){
            if(student[l][i].size()>max[i]){
                max[i]=student[l][i].size();
            }
        }
    r_length=r_length+max[i]+3;
    }r_length=r_length+1;
    
    string r1[r_length+3];
    int m=1;
    r1[0]='/';
    r1[r_length-1]='\\';
    while(m<r_length-1){
        r1[m]='-';
        m++;
    }
    m=0;
    while(m<r_length-1){
        cout<<r1[m];
        m++;
    }
     cout<<r1[r_length-1]<<endl;
    
    m=0;
    r1[0]='|';
    for(int t1=0;t1<r_numStudents;t1++){
        for(int t2=0;t2<r_numInfos;t2++){
            cout<<"| "<<student[t1][t2];
            for(int t3=0;t3<=max[t2]-student[t1][t2].size();t3=t3+1){
                printf(" ");
            }
        }
        printf("|\n");
        if(t1<r_numStudents-1){
        for(int q=0;q<r_length;q++){
            r1[q]='-';
        }
        r1[0]='|';
        for(int q2=0;q2<r_numInfos;q2++){
            q3=q3+max[q2]+3;
            r1[q3]="|";
        }
        for(int q1=0;q1<r_length;q1++){
            cout<<r1[q1];
        } 
        cout<<endl;
        }
    }


    m=1;
    r1[0]='\\';
    r1[r_length-1]='/';
    while(m<r_length-1){
        r1[m]='-';
        m++;
    }
    m=0;
    while(m<r_length){
        cout<<r1[m];
        m++;
    }
    delete [] max;
}

//////////////////////////////////////////////////////////////////////
///////////////// DO NOT SUBMIT THE FOLLOWING LINES //////////////////
//////////////////////////////////////////////////////////////////////
int main()
{
    int m, n, sortOption;
    std::cin >> m >> n >> sortOption;
    getchar();
    ReportParser p(n, m);
    p.readReport();
    p.writeStructuredReport(sortOption);
    return 0;
}