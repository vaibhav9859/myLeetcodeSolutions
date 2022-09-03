class Solution {
public:
string fractionAddition(string expression) {
    istringstream in(expression);
    char chr;

    int A = 0, B = 1, a, b;

    while (in >> a >> chr >> b) {
        A = A * b + a * B;
        B *= b;
        int g = abs(__gcd(A, B));
        A /= g;
        B /= g;
    }
    return to_string(A) + '/' + to_string(B);
}
};