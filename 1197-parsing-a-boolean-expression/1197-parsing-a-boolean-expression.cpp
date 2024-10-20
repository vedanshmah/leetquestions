class Solution {
public:
    char solve(vector<char> ele,char op){
        if(op=='!'){
            if(ele[0]=='t'){
                return 'f';
            }
            else{
                return 't';
            }
        }

        if(op=='&'){
            for(int i=0;i<ele.size();i++){
                if(ele[i]=='f'){
                    return 'f';
                }
            }
            return 't';
        }

        if(op=='|'){
            for(int i=0;i<ele.size();i++){
                if(ele[i]=='t'){
                    return 't';
                }
            }
            return 'f';
        }
        return 't';
    }
    bool parseBoolExpr(string expression) {
        stack<char> st;
        
        for(int i=0;i<expression.length();i++){
            if(expression[i]==','){
                continue;
            }
            st.push(expression[i]);
            if(st.top()==')'){
                st.pop();
                vector<char> ele;
                while(st.top()!='('){
                    ele.push_back(st.top());
                    st.pop();
                }
                st.pop();
                char op=st.top();
                st.pop();
                st.push(solve(ele,op));
            }
        }
        if(st.top()=='t'){
            return true;
        }
        else{
            return false;
        }
    }
};