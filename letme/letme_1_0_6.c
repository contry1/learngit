class Solution {
public:
    string compressString(string S) {
        string str = S;
if (str.length() == 0)
            return str;

        int cnt = 0;
        char c = str[0];
        string ans;
        for (int i = 0; i < str.length(); ++i)
        {
            if (str[i] == c)
            {

                cnt++;
            }
            else
            {
                ans.push_back(c);

                string num = to_string(cnt);
                for(char &ch:num)
                    ans.push_back(ch);
                    //ans.push_back(cnt + 48);
                c = str[i];
                cnt = 1;

            }

        }

        //mp.emplace_hint(mp.begin(),c+1, cnt);
        //key is same ,so used mutilmap,but mutilmap insert and  emplace_hint is seriers,so it can't be used!


        ans.push_back(c);
    //  ans.push_back(cnt + 48); 
    //line 38这里用line39-line41 代替
        string num2 = to_string(cnt);
                for(char &ch:num2)
                    ans.push_back(ch);

        cout << str.length() << ans.size() << endl;
        if (str.length() <= ans.size())
            return str;
        else
            return ans;
    }
};
