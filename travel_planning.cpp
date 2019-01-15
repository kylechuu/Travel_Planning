#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<limits.h>
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
    private:
        int Node;
        int Edge;
        int QuotaTime;
        int StartTime;
        city viewInfo;
        vector<city> ViewSite;
        vector<vector<int> > adjmatrix;
};
int main(int argc, char *argv[]){
    string Input, Output_one, Output_two;
    Input.assign(argv[1]);
    plan ProblemOne;
    return 0;
}
plan::plan(){
    Node = 0;
    Edge = 0;
    QuotaTime = 0;
    StartTime = 0;
}
void plan::Readfiles(string Input){
    string start, end, Output_one, Output_two;
    int cost = 0, indexStart = 0, indexEnd = 0;
    Output_one = Input + "/ans1.txt";
    Output_two = Input + "/ans2.txt";
    Input = Input + "/tp.data";
    ifstream CityInfo(Input);
    ofstream Result(Output_one);
    //ofstream ResultTwo(Output_two);
    if(CityInfo.is_open() && Result.is_open()){
        CityInfo>>Node; CityInfo>>Edge; CityInfo>>QuotaTime; CityInfo>>StartTime;
        //ViewSite.resize(Node);
        for(int i = 0; i < Node; i++){
            CityInfo>>viewInfo.CityName; CityInfo>>viewInfo.HappyIndex; CityInfo>>viewInfo.OpenTime; CityInfo>> viewInfo.CloseTime; 
            viewInfo.index = i;
            ViewSite.push_back(viewInfo);
        }
        for(int i = 0; i < Edge; i++){
            CityInfo>>start; CityInfo>>end; CityInfo>>cost;
            for(int j = 0; j < Node; j++){
                if(ViewSite[j].CityName == start)   indexStart = j;
                if(ViewSite[j].CityName == end)     indexEnd = j;   
            }
            adjmatrix[indexStart][indexEnd] = cost;
        }
    }
    CityInfo.close();
    Result.close();    
}
void plan::inialize(int start){
    adjmatrix.resize(Node);
    for(int i = 0; i < Node; i++) adjmatrix[i].resize(Node);
    for(int i = 0; i < Node; i++)
        for(int j = 0; j < Node; j++){
            adjmatrix[i][j] = INT32_MIN;
        }
    precessor[]
}
void plan::dijkstra(int start){
    inialize(start);
}