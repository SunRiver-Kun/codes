#include<iostream>
using namespace std;
template <class T,unsigned int N>
class Student
{
private:
    int id;
    T score[N];
public:
    Student(int id,T score[N]){
        this->id = id;
        for(int i=0;i<N;i++)
            this->score[i] = score[i];
    }
    T getMaxScore(){
        T MaxScore = score[0];
        for(int i=0;i<N;i++)
            if(MaxScore<score[i])
                MaxScore = score[i];
        return MaxScore;
    }
    T getMinScore(){
        T MinScore = score[0];
        for(int i=0;i<N;i++)
            if(MinScore>score[i])
                MinScore = score[i];
        return MinScore;
    }
    T getAveScore(){
        if(N==0)
        {
            cout<<"学生成绩个数输入错误";
            return -1;
        }
        T AveScore = 0;
        for(int i=0;i<N;i++)
            AveScore+=score[i];
        AveScore/=N;
        return AveScore;
    }
    T getPassed(){
        int Passed = 0;
        for(int i=0;i<N;i++)
            if(score[i]>=60)
                Passed++;
        return Passed;
    }
};

int main(){
    int id,score[3];
    cin>>id;
    for(int i=0;i<3;i++)
        cin>>score[i];
    Student<int,3>student(id,score);
    cout<<student.getMaxScore()<<" "<<student.getMinScore()<<" "<<student.getAveScore()<<" "<<student.getPassed();


}
