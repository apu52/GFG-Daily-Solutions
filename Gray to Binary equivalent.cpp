class Solution{
    public:
    int grayToBinary( int g ) {
    int b{};
    do b ^= g;
    while ( g /= 2 );
    return b;
    }
};
