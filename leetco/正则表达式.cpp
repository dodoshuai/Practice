/**
10.正则表达式匹配 
*/
 bool isMatch(string s, string p) {
        if(p.size()==0)
            return s.empty();
        if(p.size()==1)
            return (s.size()==1 && (s[0]==p[0]||p[0]=='.'));
        if(p.size()>1&&p[1]=='*'){
            return isMatch(s,p.substr(2))||(!s.empty()&&(s[0]==p[0]||p[0]=='.'))&&isMatch(s.substr(1),p);
        }
        else{
            return (!s.empty()&&(s[0]==p[0]||p[0]=='.'))&&isMatch(s.substr(1),p.substr(1));
        }
       
    }
