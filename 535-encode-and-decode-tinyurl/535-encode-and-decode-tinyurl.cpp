class Solution {
public:

    // Encodes a URL to a shortened URL.
    unordered_map<string, string> l2s;
    unordered_map<string, string> s2l;
    int count;
    
    string encode(string longUrl) {
    
        if(l2s[longUrl] != ""){
            return l2s[longUrl];
        }    
        else{
            count++; string temp = to_string(count);
            l2s[longUrl] = "http://tinyurl.com/" + temp;
            
            s2l["http://tinyurl.com/" + temp] = longUrl;
        }
        
        return l2s[longUrl];
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return s2l[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));