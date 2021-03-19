#include <bits/stdc++.h>

using namespace std;

#define pi pair< int,pair<int,int> >
#define fi first
#define se second

vector< pair<int,int> > vect[21];
map<int,int> m;

int arrival_time[21];
int finish_time[21];
int start_time[21];
int cpu_time[21];
int cpu_used[21];
bool visit[21];
bool vis[21];

int pid,art,ct,task = 0,c = 0,clk = 0;

void executeFCFS(int task)
{
    queue< pi > ready_queue;
    int index =  0,complete_task = 0;
    for(int i=1;i<21;i++)
    {
        if(visit[i])
        {
            if( m.find(arrival_time[i]) == m.end() )
            {
                m[arrival_time[i]] = index;
                vect[index].push_back({cpu_time[i],i});
                index++;
            }
            else
            {
                vect[m[arrival_time[i]]].push_back({cpu_time[i],i});
            }
        }
    }
    while(1)
    {
        if(complete_task == task)
        {
            if(task>0)
                cout<<" <system time "<<clk<<"> All processes finish ...................."<<endl;
            else
                cout<<" There are no processes"<<endl;
            break;
        }
        if(m.find(clk) != m.end())
        {
            for(int i=0;i<vect[m[clk]].size();i++)
            {
                int id = vect[m[clk]][i].se;
                //cout<<id<<endl;
                if(!vis[id])
                {
                    ready_queue.push({vect[m[clk]][i].fi,{id,arrival_time[id]}});
                    vis[id] = true;
                }
            }
        }
        if(!ready_queue.empty())
        {
            pi top = ready_queue.front();
            pid = top.se.fi;
            start_time[pid] = clk;
            ready_queue.pop();
            while(1)
            {
                if(cpu_used[pid] == cpu_time[pid])
                {
                    cout<<" <system time "<<clk<<"> process "<<pid<<" is finished....... "<<endl;
                    complete_task++;
                    finish_time[pid] = clk;
                    break;
                }
                else
                {
                    cout<<" <system time "<<clk<<"> process "<<pid<<" is running "<<endl;
                    cpu_used[pid]++;
                }
                clk++;
                if(m.find(clk) != m.end())
                {
                    for(int i=0;i<vect[m[clk]].size();i++)
                    {
                        int id = vect[m[clk]][i].se;
                        //cout<<id<<endl;
                        if(!vis[id])
                        {
                            ready_queue.push({vect[m[clk]][i].fi,{id,arrival_time[id]}});
                            vis[id] = true;
                        }
                    }
                }
            }
        }
        else
        {
            cout<<" <system time "<<clk<<"> There are no processes in ready queue..... "<<endl;
            clk++;
        }
    }
    int wt=0,rt=0,tt=0;
    for(int i=1;i<21;i++)
    {
        if(visit[i])
        {
            wt += finish_time[i] - arrival_time[i] - cpu_time[i];
            rt += start_time[i] - arrival_time[i];
            tt += finish_time[i] - arrival_time[i];
        }
    }
    cout<<"============================================================"<<endl;
    cout<<fixed;
    cout<<"Average waiting time "<<setprecision(6)<< wt/((1.0)*(task))<<endl;
    cout<<"Average response time "<<setprecision(6)<< rt/((1.0)*(task)) <<endl;
    cout<<"Average turnaround time "<<setprecision(6)<< tt/((1.0)*(task)) <<endl;
    return;
}

void executeSJF(int task)
{
    priority_queue< pi, vector<pi>, greater<pi> > ready_queue;
    int index =  0,complete_task = 0;
    for(int i=1;i<21;i++)
    {
        if(visit[i])
        {
            if( m.find(arrival_time[i]) == m.end() )
            {
                m[arrival_time[i]] = index;
                vect[index].push_back({cpu_time[i],i});
                index++;
            }
            else
            {
                vect[m[arrival_time[i]]].push_back({cpu_time[i],i});
            }
        }
    }
    while(1)
    {
        if(complete_task == task)
        {
            if(task>0)
                cout<<" <system time "<<clk<<"> All processes finish ...................."<<endl;
            else
                cout<<" There are no processes"<<endl;
            break;
        }
        if(m.find(clk) != m.end())
        {
            for(int i=0;i<vect[m[clk]].size();i++)
            {
                int id = vect[m[clk]][i].se;
                //cout<<id<<endl;
                if(!vis[id])
                {
                    ready_queue.push({vect[m[clk]][i].fi,{id,arrival_time[id]}});
                    vis[id] = true;
                }
            }
        }
        if(!ready_queue.empty())
        {
            pi top = ready_queue.top();
            pid = top.se.fi;
            start_time[pid] = clk;
            ready_queue.pop();
            while(1)
            {
                if(cpu_used[pid] == cpu_time[pid])
                {
                    cout<<" <system time "<<clk<<"> process "<<pid<<" is finished....... "<<endl;
                    complete_task++;
                    finish_time[pid] = clk;
                    break;
                }
                else
                {
                    cout<<" <system time "<<clk<<"> process "<<pid<<" is running "<<endl;
                    cpu_used[pid]++;
                }
                clk++;
                if(m.find(clk) != m.end())
                {
                    for(int i=0;i<vect[m[clk]].size();i++)
                    {
                        int id = vect[m[clk]][i].se;
                        //cout<<id<<endl;
                        if(!vis[id])
                        {
                            ready_queue.push({vect[m[clk]][i].fi,{id,arrival_time[id]}});
                            vis[id] = true;
                        }
                    }
                }
            }
        }
        else
        {
            cout<<" <system time "<<clk<<"> There are no processes in ready queue..... "<<endl;
            clk++;
        }
    }
    int wt=0,rt=0,tt=0;
    for(int i=1;i<21;i++)
    {
        if(visit[i])
        {
            wt += finish_time[i] - arrival_time[i] - cpu_time[i];
            rt += start_time[i] - arrival_time[i];
            tt += finish_time[i] - arrival_time[i];
        }
    }
    cout<<"============================================================"<<endl;
    cout<<fixed;
    cout<<"Average waiting time "<<setprecision(6)<< wt/((1.0)*(task))<<endl;
    cout<<"Average response time "<<setprecision(6)<< rt/((1.0)*(task)) <<endl;
    cout<<"Average turnaround time "<<setprecision(6)<< tt/((1.0)*(task)) <<endl;
    return;
}

void executeRR(int task,string quantum)
{
    deque< pi > ready_queue;

    int index =  0,complete_task = 0,time_slice;
    stringstream time(quantum);
    time >> time_slice;

    for(int i=1;i<21;i++)
    {
        if(visit[i])
        {
            if( m.find(arrival_time[i]) == m.end() )
            {
                m[arrival_time[i]] = index;
                vect[index].push_back({cpu_time[i],i});
                index++;
            }
            else
            {
                vect[m[arrival_time[i]]].push_back({cpu_time[i],i});
            }
        }
    }
    while(1)
    {
        if(complete_task == task)
        {
            if(task>0)
                cout<<" <system time "<<clk<<"> All processes finish ...................."<<endl;
            else
                cout<<" There are no processes"<<endl;
            break;
        }
        if(m.find(clk) != m.end())
        {
            for(int i=0;i<vect[m[clk]].size();i++)
            {
                int id = vect[m[clk]][i].se;
                //cout<<"a"<<id<<" "<<vis[id]<<"     ";
                if(vis[id] == false)
                {
                    ready_queue.push_back({vect[m[clk]][i].fi,{id,arrival_time[id]}});
                    vis[id] = true;
                    //cout<<"xx   ";
                }
                //cout<<vis[id]<<endl;
            }
        }
        if(!ready_queue.empty())
        {
            pi top = ready_queue.front();
            pid = top.se.fi;
            if(start_time[pid] == -1)
                start_time[pid] = clk;
            ready_queue.pop_front();
            int temp = time_slice;
            while(temp--)
            {
                cout<<" <system time "<<clk<<"> process "<<pid<<" is running "<<endl;
                cpu_used[pid]++;
                clk++;
                if(cpu_used[pid] == cpu_time[pid])
                {
                    cout<<" <system time "<<clk<<"> process "<<pid<<" is finished....... "<<endl;
                    complete_task++;
                    //cout<<".."<<complete_task<<endl;
                    finish_time[pid] = clk;
                    break;
                }
                if(m.find(clk) != m.end())
                {
                    for(int i=0;i<vect[m[clk]].size();i++)
                    {
                        int id = vect[m[clk]][i].se;
                        //cout<<"b"<<id<<" "<<vis[id]<<"            ";
                        if(!vis[id])
                        {
                            ready_queue.push_back({vect[m[clk]][i].fi,{id,arrival_time[id]}});
                            vis[id] = true;
                            //cout<<"xx   ";
                        }
                        //cout<<"b"<<id<<" "<<vis[id]<<endl;
                    }
                }
            }
            if(cpu_used[pid] != cpu_time[pid])
            {
                ready_queue.push_back({cpu_time[pid],{pid,arrival_time[pid]}});
            }
        }
        else
        {
            cout<<" <system time "<<clk<<"> There are no processes in ready queue..... "<<endl;
            clk++;
        }
    }
    int wt=0,rt=0,tt=0;
    for(int i=1;i<21;i++)
    {
        if(visit[i])
        {
            wt += finish_time[i] - arrival_time[i] - cpu_time[i];
            rt += start_time[i] - arrival_time[i];
            tt += finish_time[i] - arrival_time[i];
        }
    }
    cout<<"============================================================"<<endl;
    cout<<fixed;
    cout<<"Average waiting time "<<setprecision(6)<< wt/((1.0)*(task))<<endl;
    cout<<"Average response time "<<setprecision(6)<< rt/((1.0)*(task)) <<endl;
    cout<<"Average turnaround time "<<setprecision(6)<< tt/((1.0)*(task)) <<endl;
    return;
}

int main()
{
    for(int i=0;i<21;i++)   visit[i] = vis[i] = false;
    for(int i=0;i<21;i++)   cpu_used[i] = 0;
    for(int i=0;i<21;i++)   start_time[i] = -1;

    string s,str="";
    getline(cin,s);

    vector<string> argv;

    int len = s.length();
    for(int i=0;i<len;i++)
    {
        if(s[i]==' ')
        {
            argv.push_back(str);
            str = "";
        }
        else
            str += s[i];
    }
    argv.push_back(str);

    for(int i=0;i<argv.size();i++)
            cout<<argv[i]<<" ";
    cout<<endl;

    if(argv[0] == "sched")
    {
        cout<<"Scheduling algorithm: "<<argv[2]<<endl;

        string filename = argv[1];
        ifstream infile(filename.c_str());
        if(infile.is_open())
        {
            while(infile >> pid >> art >> ct)
            {
                task++;
                cout<<pid<<" "<<art<<" "<<ct<<endl;
                visit[pid] = true;
                arrival_time[pid] = art;
                cpu_time[pid] = ct;
            }
            cout<<"Total "<<task<<" tasks are read from '"<<argv[1]<<"'. press 'enter' to start..."<<endl;
            if(cin.get()=='\n')
            {
                if(argv[2]=="FCFS")
                {
                    executeFCFS(task);
                }
                else if(argv[2]=="SJF")
                {
                    executeSJF(task);
                }
                else if(argv[2]=="RR")
                {
                    executeRR(task,argv[3]);
                }
                else
                {
                    cout<<"error: enter valid scheduling algorithm"<<endl;
                }
            }
        }
        else
        {
            cout<<"error: can't open file with given name"<<endl;
        }
    }
    return 0;
}
