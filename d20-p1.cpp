#include <bits/stdc++.h>
using namespace std;
class con
{
    public:
        unordered_map<string, bool> inputs;
        vector<string> out;
        con() 
        {
            
        }
        con(vector<string> v)
        {
            out = v;
        }
        int output()
        {
            int c = 0;
            for(auto j: inputs)
                if(j.second == 1) 
                    c++;
            if(c == (int) inputs.size())
                return 0;
            return 1;
        }
        void set_input(string s, int pulse)
        {
            inputs[s] = pulse;
        }
};

class ff
{
    public:
        bool state; // 0: off, 1 : on
        vector<string> out;
        ff()
        {

        }
        ff(vector<string> o)
        {
            state = 0;
            for(auto j: o)
                out.push_back(j);
        }
        int output(int pulse)
        {
            if(pulse == 0)
            {
                if(state == 0)
                {
                    state = 1;
                    return 1;
                }
                else
                {
                    state = 0;
                    return 0;
                }
            }
            return 2;
        }
};


void solve(vector<string> &a)
{
    vector<string> bcs;
    string temp = "";
    int j = 15;
    while(j < (int) a[0].size())
    {
        if(a[0][j] >= 'a' && a[0][j] <= 'z')
            temp += a[0][j];
        else
        {
            if(temp != "")
                bcs.push_back(temp);
            temp = "";
        }
        j++;
    }
    if(temp != "")
        bcs.push_back(temp);


    unordered_map<string, ff> ffmp;
    unordered_map<string, con> conmp;



    for(int i = 1; i < (int) a.size(); i++)
    {
        if(a[i] == "") 
            continue;
        char type = a[i][0];
        string name = "";
        int j = 1;
        while(a[i][j] != ' ')
        {
            name += a[i][j];
            j++;
        }
        j += 4;
        vector<string> out;
        string temp = "";
        while(j < (int) a[i].size())
        {
            if(a[i][j] >= 'a' && a[i][j] <= 'z')
                temp += a[i][j];
            else
            {
                if(temp != "")
                    out.push_back(temp);
                temp = "";
            }
            j++;
        }
        if(temp != "")
            out.push_back(temp);
        if(type == '%')
        {
            ff f(out);
            ffmp[name] = f;
        }
        else
        {
            con c(out);
            conmp[name] = c;
        }

    }
    
    for(auto j: ffmp)
    {
        ff f = j.second;
        for(auto module: f.out)
            if(conmp.find(module) != conmp.end())
                conmp[module].inputs[j.first] = 0;
    }

    for(auto j: conmp)
    {
        con c = j.second;
        for(auto module: c.out)
            if(conmp.find(module) != conmp.end())
                conmp[module].inputs[j.first] = 0;
    }

    int al = 0;
    int ah = 0;
    for(int s = 0; s < 1000; s++)
    {
        queue<pair<string, bool>> q; 
        for(auto j: bcs)
            q.push({j, 0});
        int low = 1;
        int high = 0;
        while(!q.empty())
        {
            string name = q.front().first;
            bool input_pulse = q.front().second;
            if(input_pulse == 0) 
                low++;
            else 
                high++;
            q.pop();
            if(ffmp.find(name) != ffmp.end())
            {
                int output_pulse = ffmp[name].output(input_pulse);
                if(output_pulse == 2) continue;
                for(auto j: ffmp[name].out)
                {
                    if(conmp.find(j) != conmp.end())
                        conmp[j].set_input(name, output_pulse);
                    q.push({j, output_pulse});
                }
            }
            else if(conmp.find(name) != conmp.end())
            {
                int output_pulse = conmp[name].output();
                for(auto j: conmp[name].out)
                {
                    if(conmp.find(j) != conmp.end())
                        conmp[j].set_input(name, output_pulse);
                    q.push({j, output_pulse});
                }
            }
        }
        al += low;
        ah += high;
    }
    cout << al << " " << ah << " " << al*ah << '\n';
}
int main()
{
    ifstream in("input.in");
    vector<string> input;
    while (!in.eof())
    {
        string text;
        getline(in, text);
        if(text != "");
        input.push_back(text);
        
    }
    solve(input);
    return 0;
}
