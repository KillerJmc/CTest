#include <iostream>
#include <vector>
#include <ranges>
#include <algorithm>
#include <jmc-libs/all.h>

namespace lambda_plus {
	void main() {
		auto names = jmc::file::lines("../src/test/practice/lambda/students.dat");
		auto tmp = names
			| std::views::filter([](const auto& s) { return !s.starts_with("B") && !s.ends_with("n"); })
			| std::views::transform(jmc::str::to_upper_case);

		auto res = std::vector(tmp.begin(), tmp.end());
		std::ranges::sort(res);

		std::ranges::for_each(res, [](const auto& s) {std::cout << s << std::endl; });
	}
}