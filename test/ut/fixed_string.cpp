#include <boost/mp.hpp>
#include <boost/ut.hpp>
#include <string_view>

template <boost::mp::fixed_string Str>
static constexpr auto str = Str;

int main() {
  using namespace boost::ut;
  using std::literals::operator""sv;

  "make fixed_string"_test = [] {
    expect(constant<""sv == str<"">>);
    expect(constant<"Foo"sv == str<"Foo">>);
  };

  "make fixed_string with characters"_test = [] {
    expect(constant<std::string_view{boost::mp::fixed_string{}}.empty()>);
    expect(constant<"abc"sv == boost::mp::fixed_string{'a', 'b', 'c'}>);
    expect(constant<"abc"sv == str<boost::mp::fixed_string{'a', 'b', 'c'}>>);
  };

  "compare"_test = [] {
    constexpr auto foo = str<"Foo">;
    expect(constant<foo == str<"Foo">>);
    expect(constant<foo != str<"Bar">>);
  };
}
