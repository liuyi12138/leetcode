class Solution {
public:
    string entityParser(string text) {
        for(int i = 0; i < text.size(); ++i){
            // cout << text << endl;
            if(text.compare(i, 6, "&quot;") == 0){
                text.replace(i, 6, "\"");
                continue;
            }
            if(text.compare(i, 6, "&apos;") == 0){
                text.replace(i, 6, "\'");
                continue;
            }
            if(text.compare(i, 5, "&amp;") == 0){
                text.replace(i, 5, "&");
                continue;
            }
            if(text.compare(i, 4, "&gt;") == 0){
                text.replace(i, 4, ">");
                continue;
            }
            if(text.compare(i, 4, "&lt;") == 0){
                text.replace(i, 4, "<");
                continue;
            }
            if(text.compare(i, 7, "&frasl;") == 0){
                text.replace(i, 7, "/");
                continue;
            }
        }
        return text;
    }
};