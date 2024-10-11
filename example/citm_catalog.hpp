//
// Copyright (c) 2021 Peter Dimov
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// Official repository: https://github.com/boostorg/json
//

#ifndef BOOST_JSON_EXAMPLE_CITM_CATALOG_HPP
#define BOOST_JSON_EXAMPLE_CITM_CATALOG_HPP

#include <boost/describe/class.hpp>
#include <boost/variant2/variant.hpp>
#include <map>
#include <vector>

struct event
{
    std::nullptr_t description;
    unsigned long long id;
    boost::variant2::variant<std::nullptr_t, std::string> logo;
    std::string name;
    std::vector<unsigned long long> subTopicIds;
    std::nullptr_t subjectCode;
    std::nullptr_t subtitle;
    std::vector<unsigned long long> topicIds;
};

BOOST_DESCRIBE_STRUCT(event, (), (description, id, logo, name, subTopicIds, subjectCode, subtitle, topicIds))

struct price
{
    unsigned amount;
    unsigned long long audienceSubCategoryId;
    unsigned long long seatCategoryId;
};

BOOST_DESCRIBE_STRUCT(price, (), (amount, audienceSubCategoryId, seatCategoryId))

struct area
{
    unsigned long long areaId;
    std::vector<unsigned long long> blockIds;
};

BOOST_DESCRIBE_STRUCT(area, (), (areaId, blockIds))

struct seatCategory
{
    std::vector<area> areas;
    unsigned long long seatCategoryId;
};

BOOST_DESCRIBE_STRUCT(seatCategory, (), (areas, seatCategoryId))

struct performance
{
    unsigned long long eventId;
    unsigned long long id;
    boost::variant2::variant<std::nullptr_t, std::string> logo;
    std::nullptr_t name;
    std::vector<price> prices;
    std::vector<seatCategory> seatCategories;
    std::nullptr_t seatMapImage;
    unsigned long long start;
    std::string venueCode;
};

BOOST_DESCRIBE_STRUCT(performance, (), (eventId, id, logo, name, prices, seatCategories, seatMapImage, start, venueCode))

struct citm_catalog
{
    std::map<std::string, std::string> areaNames;
    std::map<std::string, std::string> audienceSubCategoryNames;
    std::map<std::string, std::string> blockNames;
    std::map<std::string, event> events;
    std::vector<performance> performances;
    std::map<std::string, std::string> seatCategoryNames;
    std::map<std::string, std::string> subTopicNames;
    std::map<std::string, std::string> subjectNames;
    std::map<std::string, std::string> topicNames;
    std::map<std::string, std::vector<unsigned long long>> topicSubTopics;
    std::map<std::string, std::string> venueNames;
};

BOOST_DESCRIBE_STRUCT(citm_catalog, (),
    (areaNames, audienceSubCategoryNames, blockNames, events, performances,
    seatCategoryNames, subTopicNames, subjectNames, topicNames, topicSubTopics, venueNames))

#endif // BOOST_JSON_EXAMPLE_CITM_CATALOG_HPP
