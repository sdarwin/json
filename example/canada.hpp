//
// Copyright (c) 2021 Peter Dimov
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// Official repository: https://github.com/boostorg/json
//

#ifndef BOOST_JSON_EXAMPLE_CANADA_HPP
#define BOOST_JSON_EXAMPLE_CANADA_HPP

#include <boost/describe/class.hpp>

#include <map>
#include <string>
#include <vector>
#include <utility>

struct geometry_type
{
    std::string type;
    std::vector< std::vector<std::pair<double, double>> > coordinates;
};

BOOST_DESCRIBE_STRUCT(geometry_type, (), (type, coordinates))

struct feature
{
    std::string type;
    std::map<std::string, std::string> properties;
    geometry_type geometry;
};

BOOST_DESCRIBE_STRUCT(feature, (), (type, properties, geometry))

struct canada
{
    std::string type;
    std::vector<feature> features;
};

BOOST_DESCRIBE_STRUCT(canada, (), (type, features))

#endif // BOOST_JSON_EXAMPLE_CANADA_HPP
