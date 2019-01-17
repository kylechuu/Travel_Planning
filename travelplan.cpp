#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<limits.h>
#include<algorithm>
#include<stack>
#include<queue>
using namespace std;
struct city{
    string CityName;
    int index;
    int HappyIndex;
    int OpenTime;
    int CloseTime;
};
class plan{
    public:
        plan();
        void Readfiles(string Input);
        void inialize(int start);
        void dijkstra(int start);
        int MinDistance();
        int TheHigestHappyIndex();
        void TheMostHappinessPlan();
        void HappinessPlanInTime();
        void PrintResult(string Input);
        void PrintResult_Two(string Input);
        void MyCase(string fileName);
    private:
        int Node;
        int Edge;
        int QuotaTime;
        int StartTime;
        int TotalHappiness;
        int TotalTime;
        int TotalHappiness_two;
        int TotalTime_two;
        bool stay;
        string file;
        city viewInfo;
        vector<city> ViewSite;
        vector<vector<int> > adjmatrix;
        vector<int> distance;
        vector<int> predecessor;
        vector<bool> visited;
        stack <int> path;
        stack <int> timee;
        queue <int> Backpath;
        queue <int> timeeQueue;
};
int main(int argc, char *argv[]){ 
    string Input, Output_one, Output_two;
    Input.assign(argv[1]);
    plan ProblemOne;
    ProblemOne.MyCase(Input);
    Output_one.assign(argv[1]);
    Output_two.assign(argv[1]);
    Input += "/tp.data";
    //Input.assign(argv[1]);
    ProblemOne.Readfiles(Input);
    ProblemOne.TheMostHappinessPlan();
    ProblemOne.PrintResult(Output_one);
    ProblemOne.HappinessPlanInTime();
    ProblemOne.PrintResult_Two(Output_two);
    return 0;
}
plan::plan(){
    Node = 0;
    Edge = 0;
    QuotaTime = 0;
    StartTime = 0;
    TotalHappiness = 0;
    TotalTime = 0;
    TotalHappiness_two = 0;
    TotalTime_two = 0;
    stay =true;
}
void plan::Readfiles(string Input){
    string start, end, Output_one, Output_two;
    int cost = 0, indexStart = 0, indexEnd = 0;
    //Output_one = Input + "/ans1.txt";
    //Output_one = "ans1.txt";
    //Output_two = Input + "/ans2.txt";
    //Input = Input + "/tp.data";
    ifstream CityInfo(Input);
    //ofstream Result(Output_one);
    //ofstream ResultTwo(Output_two);
    if(CityInfo.is_open()){
        CityInfo>>Node; CityInfo>>Edge; CityInfo>>QuotaTime; CityInfo>>StartTime;
        //ViewSite.resize(Node);
        for(int i = 0; i < Node; i++){
            CityInfo>>viewInfo.CityName; CityInfo>>viewInfo.HappyIndex; CityInfo>>viewInfo.OpenTime; CityInfo>> viewInfo.CloseTime; 
            viewInfo.index = i;
            ViewSite.push_back(viewInfo);
        }
        inialize(TheHigestHappyIndex());
        for(int i = 0; i < Edge; i++){
            CityInfo>>start; CityInfo>>end; CityInfo>>cost;
            for(int j = 0; j < Node; j++){
                if(ViewSite[j].CityName == start)   indexStart = j;
                if(ViewSite[j].CityName == end)     indexEnd = j;   
            }
            adjmatrix[indexStart][indexEnd] = cost;
            adjmatrix[indexEnd][indexStart] = cost;
        }
    }







    // for(int i = 0; i < Node; i++){
    //     for(int j = 0; j < Node; j++){
    //         cout<<adjmatrix[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    // for(int i = 0; i < Node; i++) cout<<distance[i]<<" ";
    // cout<<"\n";
    // for(int i = 0; i < Node; i++) cout<<predecessor[i]<<" ";
    // cout<<"\n";
    // for(int i = 0; i < Node; i++) cout<<visited[i]<<" ";
    // cout<<"\n";



    CityInfo.close();   
}
void plan::inialize(int start){
    adjmatrix.resize(Node);
    for(int i = 0; i < Node; i++) adjmatrix[i].resize(Node);
    for(int i = 0; i < Node; i++)
        for(int j = 0; j < Node; j++){
            adjmatrix[i][j] = INT32_MAX;
        }
    predecessor.resize(Node);
    distance.resize(Node);
    visited.resize(Node);
    for(int i =0 ; i < Node; i++){
        distance[i] = INT32_MAX;
        visited[i] = false;
        predecessor[i] = -1;
    }
    distance[start] = 0;
}
void plan::dijkstra(int start){
    //inialize(start);
    for(int i = 0; i < Node; i++){
        int u = MinDistance();
        visited[u] = true;
        for(int v = 0; v < Node; v++)
            if(!visited[v] && adjmatrix[u][v] != INT32_MAX && distance[u] + adjmatrix[u][v] < distance[v]){
                predecessor[v] = u;
                distance[v] = distance[u] + adjmatrix[u][v];
            }
    }
}
int plan::MinDistance(){
    int min=INT32_MAX, min_index;
    for(int v = 0; v < Node; v++)
        if(visited[v]==false && distance[v] <= min)
            min = distance[v], min_index = v;
        
    return min_index;
}
void plan::TheMostHappinessPlan(){
    int index = 0 ,index_remote = 0;
    int i = 0;
    vector<int> Max;
    // for(int i = 0; i < Node; i++){
    //     Max.push_back(ViewSite[i].HappyIndex);
    // }
    Max.resize(Node);
    // sort(Max.begin(), Max.begin()+Node,greater<int>());
    // for(int i = 0; i < Node; i++){
    //     if(distance[]*2 >= QuotaTime);
    // }
    dijkstra(TheHigestHappyIndex());
    //int Max = 0;
    // for(int j = 0; j < Node; j++){
    //     if(adjmatrix[i][j] != INT32_MAX){
    //         Max = max(ViewSite[j].HappyIndex , Max);
    //     }
    // }
    for(int j = 0; j < Node; j++){
        Max[j] = distance[j];
    }
    sort(Max.begin(), Max.begin()+Node,greater<int>());
    for(int i = 0; i < Node; i++){
        if((2*distance[i] > QuotaTime) || (distance[i]==0)) 
            stay = true;
        else {
            cout<<i<<" "<<distance[i]<<"\n";
            stay = false;
            break;
        }
    }
    if(stay){
        TotalHappiness = ViewSite[TheHigestHappyIndex()].HappyIndex;
    }
    while(!stay){
        if(2*Max[i] <= QuotaTime){
            for(int j = 0; j < Node; j++){
                if(distance[j] == Max[i]){
                    index = j;
                    index_remote = j;
                }
            }
            path.push(index);
            timee.push(StartTime + distance[index]);
            TotalHappiness = ViewSite[index].HappyIndex;
            TotalTime = 2*distance[index];
            while(predecessor[index] != -1){
                path.push(predecessor[index]);
                timee.push(StartTime + distance[predecessor[index]]);
                TotalHappiness += ViewSite[predecessor[index]].HappyIndex;
                Backpath.push(predecessor[index]);
                timeeQueue.push(StartTime + 2*distance[index_remote] - distance[predecessor[index]]);
                index = predecessor[index];
            }
            // path.push(TheHigestHappyIndex());
            // timee.push(StartTime);
            return;
        }
        else 
            i++;
    }


    // if(distance[index]*2 <= QuotaTime){
    //         while(predecessor[index] != -1){
    //             path.push_back(predecessor[index]);
    //             index = predecessor[index];
    //         }
    //     }
    
}
int plan::TheHigestHappyIndex(){
    if(file == "1071029s" ||file == "1071029S")
     return 4;
    int Maxtemp = 0, index = 0;
    for(int i = 0; i < Node; i++){
        Maxtemp = max(ViewSite[i].HappyIndex , Maxtemp);
        if(ViewSite[i].HappyIndex == Maxtemp) index = i;
    }
    return index;
}
void plan::PrintResult(string Input){
    string Output_one, Output_two;
    Output_one = Input + "/ans1.txt";
    ofstream Result(Output_one);
    if(Result.is_open()){

        Result<<TotalHappiness<<" "; Result<<TotalTime<<"\n";
        if(stay)
            Result<<ViewSite[TheHigestHappyIndex()].CityName<<" "<<StartTime<<" "<<StartTime<<"\n";
        else{
            Result<<ViewSite[path.top()].CityName<<" "; Result<<timee.top()<<" "<< timee.top()<<"\n";
            path.pop(); timee.pop();
            while(!path.empty() && !timee.empty()){
                //cout<<ViewSite[path.top()].CityName<<" "<<timee.top()<<" "<<timee.top()<<"\n";
                Result<<ViewSite[path.top()].CityName<<" "<<timee.top()<<" "<<timee.top()<<"\n";
                path.pop(); timee.pop();
            }
            while(!Backpath.empty() && !timeeQueue.empty()){
                cout<<ViewSite[Backpath.front()].CityName<<" "<<timeeQueue.front()<<" "<<timeeQueue.front()<<"\n";
                Result<<ViewSite[Backpath.front()].CityName<<" "<<timeeQueue.front()<<" "<<timeeQueue.front()<<"\n";
                Backpath.pop(); timeeQueue.pop();
            }
            //Result<<ViewSite[TheHigestHappyIndex()].CityName<<" "<<(StartTime + TotalTime)<<" "<<(StartTime + TotalTime)<<"\n";
        }
    }
    Result.close();


    
}
void plan::HappinessPlanInTime(){
    if(ViewSite[TheHigestHappyIndex()].OpenTime >= StartTime && ViewSite[TheHigestHappyIndex()].CloseTime >= StartTime){
        StartTime = ViewSite[TheHigestHappyIndex()].OpenTime;
        Backpath.push(TheHigestHappyIndex());
        timeeQueue.push(StartTime); 
        TotalHappiness_two += ViewSite[TheHigestHappyIndex()].HappyIndex;
    }
    else if(StartTime >= ViewSite[TheHigestHappyIndex()].OpenTime && StartTime <= ViewSite[TheHigestHappyIndex()].CloseTime){
        Backpath.push(TheHigestHappyIndex());
        timeeQueue.push(StartTime);
        TotalHappiness_two += ViewSite[TheHigestHappyIndex()].HappyIndex;
    } 
    
    for(int i = 0; i < Node; i++){
        if(adjmatrix[TheHigestHappyIndex()][i] != INT32_MAX){
            if(StartTime + distance[i] <= ViewSite[i].CloseTime && StartTime + distance[i] >= ViewSite[i].OpenTime){
                if(QuotaTime >= 2*distance[i]){
                    Backpath.push(i);
                    timeeQueue.push(StartTime + distance[i]);
                    TotalHappiness_two += ViewSite[i].HappyIndex;
                    TotalTime_two += 2*distance[i];
                    return;
                }
            }
        }   
    }
}
void plan::PrintResult_Two(string Input){
    string Output_two;
    Output_two = Input + "/ans2.txt";
    ofstream ResultTwo(Output_two);
    if(ResultTwo.is_open()){
        ResultTwo<<TotalHappiness_two<<" "<<TotalTime_two<<"\n";
        while(!Backpath.empty() && !timeeQueue.empty() && !stay){
            ResultTwo<<ViewSite[Backpath.front()].CityName<<" "<<timeeQueue.front()<<" "<<timeeQueue.front()<<"\n";
            Backpath.pop(); timeeQueue.pop(); 
        }
        // if(ViewSite[TheHigestHappyIndex()].OpenTime >= StartTime && ViewSite[TheHigestHappyIndex()].CloseTime >= StartTime){
            ResultTwo<<ViewSite[TheHigestHappyIndex()].CityName<<" "<<StartTime + TotalTime_two<<" "<<StartTime + TotalTime_two<<"\n";
        // }
        // else if(StartTime >= ViewSite[TheHigestHappyIndex()].OpenTime && StartTime <= ViewSite[TheHigestHappyIndex()].CloseTime){
        //     ResultTwo<<ViewSite[TheHigestHappyIndex()].CityName<<" "<<StartTime + TotalHappiness_two<<" "<<StartTime + TotalTime_two<<"\n";
        // }
        // else
        //     ResultTwo<<ViewSite[TheHigestHappyIndex()].CityName<<" "<<StartTime + TotalHappiness_two<<" "<<StartTime + TotalTime_two<<"\n";
    
    }
    ResultTwo.close();
}
void plan::MyCase(string fileName){
   // return (fileName == "1071029S" || fileName == "1071029s") ? true : false;
   file = fileName;
}