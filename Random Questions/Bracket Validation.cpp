#include <iostream>
#include <regex>

using namespace std;

int main()
{
    string s = "([)]";
    /** Not using regex. Although its a 2 liner code, for simple pattern matching, regex is very slow as compared to std::find(...).
     *
     * R"(...)" is 'raw string literal' which is needed for escape characters like [, ], etc.
     * ^ ... $ ensures that string starts & ends with brackets only.
     * ^[...]+$ ensures only the chars. mentioned in the [...] are present
     * () [] {} <- only these chars. should be present.
     */
    regex bracketsRegex = regex(R"(^[()\[\]{}]+$)");
    bool onlyContainsBracket = regex_match(s, bracketsRegex);
    cout << s << " only contains brackets: " << (onlyContainsBracket ? "true" : "false") << endl;
    return 0;
}