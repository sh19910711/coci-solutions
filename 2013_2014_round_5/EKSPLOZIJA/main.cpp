
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
  const Int SIZE = 1000000 + 11;
  typedef unsigned long long ULL;
  typedef std::array<ULL, SIZE> ULLArray;
}

// @snippet<sh19910711/contest-base-simple:solution/template-storages.cpp>
namespace solution {
  struct Input {
    String S;
    String E;
  };
  struct Output {
    String result;
  };
}

// @snippet<sh19910711/contest-base-simple:solution/solution.cpp>
namespace solution {
  struct Solution {
    //
    // Implement here
    //
    
    Int N;
    Int M;
    const ULL HASH_MOD = 277ULL;
    ULLArray hash;
    ULLArray base;
    
    void solve() {
      N = in->S.size();
      generate_base();
      generate_hash();
      out->result = "test";

      ULL he = get_hash(in->E);
      for ( Int i = in->E.size(); i <= N; ++ i ) {
        Int front = i - in->E.size();
        ULL h = hash[i] - hash[front];
        std::cout << "h = " << hash[i] << " - " << hash[front] << std::endl;
        std::cout << "front = " << front << ", i = " << i << ", hash[front] = " << hash[front] << ", base[front] = " << base[front] << std::endl;
        std::cout << i << ": " << h << " == " << he * base[front] << std::endl;
      }
    }

    void generate_base() {
      base[0] = 1;
      for ( Int i = 1; i < SIZE; ++ i ) {
        base[i] = base[i - 1] * HASH_MOD;
      }
    }

    void generate_hash() {
      hash[0] = 0;
      for ( auto i = 1; i <= N; ++ i )
        hash[i] = hash[i - 1] * HASH_MOD + (ULL)(in->S[i - 1]);
    }

    ULL get_hash( const String& s ) {
      auto len = s.size();
      ULL res = 0;
      for ( auto i = 0; i < len; ++ i ) {
        res *= HASH_MOD;
        res += (ULL)(s[i]);
      }
      return res;
    }
    
    bool input() {
      return std::cin >> in->S >> in->E;
    }
    
    void output() {
      std::cout << out->result << std::endl;
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

