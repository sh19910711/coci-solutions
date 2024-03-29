
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
  const Int SIZE = 100 + 11;
  typedef std::array<String, SIZE> StringArray;
  typedef std::set<String> StringSet;
}

// @snippet<sh19910711/contest-base-simple:solution/template-storages.cpp>
namespace solution {
  struct Input {
    Int N;
    StringArray A;
  };
  struct Output {
    Int len;
    char c;
  };
}

// @snippet<sh19910711/contest-base-simple:solution/solution.cpp>
namespace solution {
  struct Solution {
    //
    // Implement here
    //
    StringSet S;
    StringSet S_rev;

    void solve() {
      S.clear();
      S_rev.clear();
      generate_set();
      auto ret = find_password();
      out->len = ret.size();
      out->c = ret[out->len / 2];
    }

    String find_password() {
      for ( auto i = 0; i < in->N; ++ i ) {
        if ( S_rev.count(in->A[i]) )
          return in->A[i];
      }
      return "";
    }

    void generate_set() {
      for ( auto i = 0; i < in->N; ++ i ) {
        auto s = in->A[i];
        auto t = s;
        std::reverse(std::begin(t), std::end(t));
        S.insert(s);
        S_rev.insert(s);
      }
    }
    
    bool input() {
      if ( ! ( std::cin >> in->N ) )
        return false;
      for ( auto i = 0; i < in->N; ++ i )
        if ( ! ( std::cin >> in->A[i] ) )
          return false;
      return true;
    }
    
    void output() {
      std::cout << out->len << " " << out->c << std::endl;
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

