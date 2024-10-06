class Solution {
public:
vector<string> vecbnao(string s1,int n1){
    vector<string> v;
    string temp;
    for(int i=0;i<n1;i++){
        if(s1[i]==' '){
            v.push_back(temp);
            temp="";
        }
        else{
            temp=temp+s1[i];
        }
    }
    v.push_back(temp);
    return v;
}
    bool areSentencesSimilar(string s1, string s2) {
        
        if(s2.length()>s1.length()){
            swap(s1,s2);
        }
        int n1=s1.length();
        int n2=s2.length();
        vector<string> vec1=vecbnao(s1,n1);
        vector<string> vec2=vecbnao(s2,n2);

        int i=0,j=vec1.size()-1;//1 1
        int k=0,l=vec2.size()-1;//1 0

        while(k<vec2.size() && i<vec1.size() && vec2[k]==vec1[i]){
            k++;
            i++;
        }
        while(l>=k && vec2[l]==vec1[j]){
            j--;
            l--;
        }
        return l<k;
    }
};