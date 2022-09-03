class Solution {
public:
string fractionAddition(string expression) {
    istringstream in(expression);
    char chr;

    int valA = 0, valB = 1;
    int first, second;

    for(;in >> first >> chr >> second;) {
        valA = valA * second + first * valB;
        valB *= second;
        int g = abs(__gcd(valA, valB));
        valA /= g;
        valB /= g;
    }
    return to_string(valA) + '/' + to_string(valB);
}
};