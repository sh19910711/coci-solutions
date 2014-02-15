
// @snippet<sh19910711/contest-base-simple:header.cpp>
#define __THIS_IS_CPP11__
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <numeric>
#include <limits>
#include <cstdio>
#include <cmath>

#ifdef __THIS_IS_CPP11__
#include <memory>
#include <array>
#endif

// @snippet<sh19910711/contest-base-simple:solution/template-typedef.cpp>
namespace solution {
  typedef long long Int;
  typedef long double Double;
  typedef std::string String;
}

// @snippet<sh19910711/contest-base-simple:solution/template-constants.cpp>
namespace solution {
  const Int SIZE = 1024 + 11;
  typedef std::array<Int, SIZE> IntArray;
  typedef std::array<bool, SIZE> BoolArray;
}

// @snippet<sh19910711/contest-base-simple:solution/template-storages.cpp>
namespace solution {
  struct Input {
    Int K;
    IntArray A;
  };
  struct Output {
    IntArray tree;
  };
}

// @snippet<sh19910711/contest-base-simple:solution/solution.cpp>
namespace solution {
  struct Solution {
    //
    // Implement here
    //

    Int total;
    Int cur;

    void solve() {
      cur = 1;
      rec(1);
    }

    void rec( const Int& from ) {
      if ( 2 * from < total )
        rec(2 * from);
      //
      out->tree[from] = in->A[cur];
      cur += 1;
      if ( 2 * from + 1 < total )
        rec(2 * from + 1);
    }
    
    bool input() {
      if ( ! ( std::cin >> in->K ) )
        return false;
      total = 1;
      for ( Int i = 0; i < in->K; ++ i ) {
        for ( Int j = 0; j < std::pow(Int(2), i); ++ j ) {
          std::cin >> in->A[total];
          total += 1;
        }
      }
      return true;
    }
    
    void output() {
      Int cur = 1;
      for ( Int i = 0; i < in->K; ++ i ) {
        Int len = std::pow(Int(2), i);
        for ( Int j = 0; j < len; ++ j ) {
          std::cout << out->tree[cur];
          cur += 1;
          if ( j + 1 < len )
            std::cout << " ";
        }
        std::cout << std::endl;
      }
    }

    //
    //
    //
    Solution( Input* in, Output* out ): in(in), out(out) {
      // pre calc
    }
    
    int run() {
      for (;;) {
        this->before_action(-1);
        if ( ! this->action() ) { this->after_action(-1); break; }
        this->after_action(-1);
      };
      return 0;
    }
    
    bool action() {
      if ( ! this->input() ) return false;
      this->solve();
      this->output();
      return true;
    }
    
    void before_action( const int& t_id ) {}
    
    void after_action( const int& t_id ) {}
    
    Input* in;
    Output* out;
  };
}

// @snippet<sh19910711/contest-base-simple:main_func.cpp>
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  using namespace solution;
  static Input in;
  static Output out;
  static Solution sol(&in, &out);
  return sol.run();
}

// @snippet<sh19910711/contest-base-simple:main.cpp>

