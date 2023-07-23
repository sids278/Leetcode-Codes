class Solution {
public:
    string parsedString(string input){
        if(input=="&quot;"){
            string s="";
            return s+'"';
        }
        else if(input=="&apos;"){
            return "'";
        }
        else if(input=="&amp;"){
            return "&";
        }
        else if(input=="&gt;"){
            return ">";
        }
        else if(input=="&lt;"){
            return "<";
        }
        else if(input=="&frasl;")
            return "/";
        else
            return input;
    }
    string entityParser(string text) {
        string res="";
        for(int i=0;i<text.length();i++){
            
            if(text[i]=='&'){
                
                if(i+1<text.length() && text[i+1]=='&'){
                    res+=text[i];
                }
                else{
                    string temp="";
                    while(i<text.length() && text[i]!=';'){
                        temp+=text[i];
                        if(i<text.length()-1&&text[i+1]=='&')break;
                        
                        
                        i++;
                    }
                    if(i<text.length() && text[i]==';'){
                        temp+=';';
                    }
                    res+=parsedString(temp);
                }
            }
            else{
                res+=text[i];
            }


        }
        return res;
    }
};