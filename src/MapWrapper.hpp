#include <Rcpp.h>
#include <string>

namespace Rcpp{
	template <> std::map<std::string, std::string> as(SEXP sexp) {
		List in(sexp);
		CharacterVector names(in.names());
		std::map<std::string, std::string> out;

		for(int i = 0; i < names.size(); ++i)
		{
			std::string key = as<std::string>(names(i));	
			std::string value = as<std::string>(in[i]);
			out[key] = value;
		}
		return out;
	}

	// template <> SEXP wrap(const std::map<std::string, std::string> lista)
	// {
	// 	List list;

	// 	return list;
	// }
}