class Solution {
public:
    bool checkValid(char a, char b){
	if( a == b) return true;
	if(toupper(a) == toupper(b)) return false;

	return true;
}


string makeGood(string &str){
	string output;
	int sz = str.size();

	for(int i=0; i<sz; ){
		if(i == sz-1){
			if(output.size() >0){
		if(!checkValid(str[i], output.back()) ){
	i++;
	output.pop_back();
	continue;
}
}

output += str[i];
i++;
}
else {
		// let's check prev
         	if(output.size() >0){
		if(!checkValid(str[i], output.back()) ){
	i++;
	output.pop_back();
	continue;
}
}

if(!checkValid(str[i], str[i+1])){
	i = i+2;
	continue;
}

output += str[i];
i++;
}
}
	
	return output;
}

};