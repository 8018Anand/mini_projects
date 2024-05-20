#include <bits/stdc++.h>
using namespace std;

void defalutadding2(unordered_map<string,unordered_map<string,pair<int,int>>>& graph)
{
    graph["Visakhapatnam"]["Vijayawada"]={120,5000};
    graph["Visakhapatnam"]["Tirupati"]={300,21000};
    graph["Visakhapatnam"]["Rajahmundry"]={90,3000};
    graph["Visakhapatnam"]["Kurnool"]={180,15000};
    graph["Visakhapatnam"]["Kadapa"]={240,17000};

    graph["Vijayawada"]["Visakhapatnam"]={120,5000};
    graph["Vijayawada"]["Tirupati"]={180,14000};
    graph["Vijayawada"]["Rajahmundry"]={60,3000};
    graph["Vijayawada"]["Kurnool"]={90,9000};
    graph["Vijayawada"]["Kadapa"]={150,11000};

    graph["Tirupati"]["Visakhapatnam"]={300,21000};
    graph["Tirupati"]["Vijayawada"]={180,14000};
    graph["Tirupati"]["Rajahmundry"]={210,17000};
    graph["Tirupati"]["Kadapa"]={60,2500};
    graph["Tirupati"]["Kurnool"]={90,8000};


    
    graph["Kurnool"]["Visakhapatnam"]={180,15000};
    graph["Kurnool"]["Vijayawada"]={90,9000};
    graph["Kurnool"]["Tirupati"]={90,8000};
    graph["Kurnool"]["Rajahmundry"]={150,10000};
    graph["Kurnool"]["Kadapa"]={60,4000};



    
    graph["Rajahmundry"]["Visakhapatnam"]={90,3000};
    graph["Rajahmundry"]["Vijayawada"]={60,3000};
    graph["Rajahmundry"]["Tirupati"]={210,17000};
    graph["Rajahmundry"]["Kurnool"]={150,10000};
    graph["Rajahmundry"]["Kadapa"]={180,12000};





    graph["Kadapa"]["Visakhapatnam"]={240,17000};
    graph["Kadapa"]["Vijayawada"]={150,11000};
    graph["Kadapa"]["Tirupati"]={60,2500};
    graph["Kadapa"]["Kurnool"]={40,2000};
    graph["Kadapa"]["Rajahmundry"]={180,12000};
    
}


void defalutadding1(unordered_map<string,unordered_map<string,pair<int,int>>>& graph)
{
    graph["Visakhapatnam"]["Vijayawada"]={60,2500};
    graph["Vijayawada"]["Visakhapatnam"]={60,2500};

    graph["Visakhapatnam"]["Tirupati"]={90,3500};
    graph["Tirupati"]["Visakhapatnam"]={90,3500};

    // graph["Visakhapatnam"]["Kurnool"]={90,4500};
    // graph["Kurnool"]["Visakhapatnam"]={90,4500};

    graph["Visakhapatnam"]["Rajahmundry"]={60,2000};
    graph["Rajahmundry"]["Visakhapatnam"]={60,2000};

    // graph["Visakhapatnam"]["Kadapa"]={};

    graph["Vijayawada"]["Tirupati"]={70,3000};
    graph["Tirupati"]["Vijayawada"]={70,3000};

    // graph["Vijayawada"]["Kurnool"]={};

    graph["Vijayawada"]["Rajahmundry"]={60,2500};
    graph["Rajahmundry"]["Vijayawada"]={60,2500};

    // graph["Vijayawada"]["Kadapa"]={};

    // graph["Tirupati"]["Kurnool"]={};

    graph["Tirupati"]["Rajahmundry"]={90,3500};
    graph["Rajahmundry"]["Tirupati"]={60,2500};

    graph["Tirupati"]["Kadapa"]={60,2500};
    graph["Kadapa"]["Tirupati"]={60,2500};

    // graph["Kurnool"]["Rajahmundry"]={};

    // graph["Kurnool"]["Kadapa"]={};

    // graph["Rajahmundry"]["Kadapa"]={};
}

void timeefficientpath(unordered_map<string,unordered_map<string,pair<int,int>>>& graph,string src,string des)
{
    unordered_map<string,int> times{
        {"Visakhapatnam",1e9},
        {"Vijayawada",1e9},
        {"Tirupati",1e9},
        {"Rajahmundry",1e9},
        {"Kurnool",1e9},
        {"Kadapa",1e9}
    };
    unordered_map<string,string> pathfinder{
        {"Visakhapatnam","Visakhapatnam"},
        {"Vijayawada","Vijayawada"},
        {"Tirupati","Tirupati"},
        {"Rajahmundry","Rajahmundry"},
        {"Kurnool","Kurnool"},
        {"Kadapa","Kadapa"}
    };
    times[src]=0;
    set<pair<int,string>> minheap;

    minheap.insert({0,src});

    while(!minheap.empty())
    {
        auto use=*(minheap.begin());
        minheap.erase(use);
        int time=use.first;
        string port=use.second;
        for(auto ports:graph[port])
        {
            if(time+ports.second.first<times[ports.first])
            {
                if(times[ports.first]!=1e9) minheap.erase({times[ports.first],ports.first});
                times[ports.first]=time+ports.second.first;
                minheap.insert({times[ports.first],ports.first});
                pathfinder[ports.first]=port;
            }
        }
    }
    string temp=des;
    vector<string> ans;
    while(pathfinder[temp]!=temp)
    {
        ans.push_back(temp);
        temp=pathfinder[temp];
    }
    ans.push_back(temp);
    cout<<"FASTEST PATH====>  ";
    for(int i=ans.size()-1;i>=0;i--)
    {
        cout<<ans[i]<<"->";
    }
    cout<<"===>takes nearly "<<times[des]<<"min";
    cout<<endl;
    return ;
}

void costefficientpath(unordered_map<string,unordered_map<string,pair<int,int>>>& graph,string src,string des)
{
    unordered_map<string,int> costs{
        {"Visakhapatnam",1e9},
        {"Vijayawada",1e9},
        {"Tirupati",1e9},
        {"Rajahmundry",1e9},
        {"Kurnool",1e9},
        {"Kadapa",1e9}
    };
    unordered_map<string,string> pathfinder{
        {"Visakhapatnam","Visakhapatnam"},
        {"Vijayawada","Vijayawada"},
        {"Tirupati","Tirupati"},
        {"Rajahmundry","Rajahmundry"},
        {"Kurnool","Kurnool"},
        {"Kadapa","Kadapa"}
    };
    costs[src]=0;
    set<pair<int,string>> minheap;

    minheap.insert({0,src});

    while(!minheap.empty())
    {
        auto use=*(minheap.begin());
        minheap.erase(use);
        int cost=use.first;
        string port=use.second;
        for(auto ports:graph[port])
        {
            if(cost+ports.second.second<costs[ports.first])
            {
                if(costs[ports.first]!=1e9) minheap.erase({costs[ports.first],ports.first});
                costs[ports.first]=cost+ports.second.second;
                minheap.insert({costs[ports.first],ports.first});
                pathfinder[ports.first]=port;
            }
        }
    }
    string temp=des;
    vector<string> ans;
    while(pathfinder[temp]!=temp)
    {
        ans.push_back(temp);
        temp=pathfinder[temp];
    }
    ans.push_back(temp);
    cout<<"chepest PATH====>  ";
    for(int i=ans.size()-1;i>=0;i--)
    {
        cout<<ans[i]<<"->";
    }
    cout<<"===>takes nearly "<<costs[des]<<"rs";
    cout<<endl;
    return ;
}

int main()
{
    unordered_map<string,unordered_map<string,pair<int,int>>> graph;
    defalutadding2(graph);
    vector<string> services{"Visakhapatnam","Vijayawada","Tirupati","Rajahmundry","Kurnool","Kadapa"};
    string source;
    string destination;
    cout<<"Hello there.....,"<<endl;
    cout<<"We are providing services among these airports==> ";
    for(auto it:services) cout<<it<<" ";
    cout<<endl;
    cout<<"From:";
    cin>>source;
    if((find(services.begin(),services.end(),source)==services.end()))
    {
        cout<<"Sorry this "<<source<<" airport is not recognised.";
        exit(0);
    }
    else if(graph.find(source)==graph.end())
    {
        cout<<"Sorry there is no outgoing flights for the "<<source;
        exit(0);
    }
    cout<<"To:";
    cin>>destination;
    if(find(services.begin(),services.end(),destination)==services.end()) 
    {
        cout<<"Sorry this"<< destination <<"airport is not recognised.";
        exit(0); 
    }
    else if(graph.find(destination)==graph.end())
    {
        cout<<"sorry there is no incoming flights for the "<<destination;
        exit(0);
    }
    timeefficientpath(graph,source,destination);

    costefficientpath(graph,source,destination);

    

    

    return 0;
}