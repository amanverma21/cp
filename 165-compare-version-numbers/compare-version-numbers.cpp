class Solution {
public:
    long long  solve( string s )
    {
        long long n = 0 ;
        int i = 0 ;
        while( i < s.size() ) 
        {
            n += n*10 + (s[i]-'0') ;
            i++ ;
        }
        return n ;
    }
    int compareVersion(string v1, string v2 ) {
        int i = 0 , j = 0 ;
        while( i < v1.size() && j < v2.size() )
        {
            string q1 = "" , q2 = "" ;
            while( i < v1.size() && v1[i]!='.')
            {
                q1.push_back( v1[i] ) ;
                i++ ;
            }
            while( j < v2.size() && v2[j]!='.')
            {
                q2.push_back( v2[j] ) ;
                j++ ;
            }
            int p = solve( q1 ) ; int s = solve( q2 ) ;
            if( p > s )         return 1 ;
            else if( p < s )    return -1 ;
            i++ ; j++ ;
        }
        while( i < v1.size() )
        {
            string q1 = "" ;
            while( i < v1.size() && v1[i]!='.')
            {
                q1.push_back( v1[i] ) ;
                i++ ;
            }
            int p = solve( q1 ) ; int s = 0 ;
            if( p > s )         return 1 ;
            else if( p < s )    return -1 ;
            i++ ;
        }
        while( j < v2.size() ) 
        {
            string q2 = "" ;
            while( j < v2.size() && v2[j]!='.')
            {
                q2.push_back( v2[j] ) ;
                j++ ;
            }
            int p = 0 ; int s = solve( q2 ) ;
            if( p > s )         return 1 ;
            else if( p < s )    return -1 ;
            j++ ;
        }
        return 0 ;
    }
};