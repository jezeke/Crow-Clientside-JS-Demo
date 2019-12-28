/*
 A great backend must begin with the unmeasurable,
 must go through measurable means when it is being designed
 and in the end must be unmeasurable.

 This is not a great backend.
 ----------------------------

 Infrastructure is much more important than architecture.

 The design of this backend considered neither very strongly.
 ------------------------------------------------------------

 */

#include "crow.h"
#include <string>
#include <vector>
#include <chrono>

int main()
{
  crow::SimpleApp app;
  crow::mustache::set_base(".");

  CROW_ROUTE(app, "/crow/error")
  .methods("POST"_method)
  ([](const crow::request& req)
  {
    int length;

    try
    {
      length = std::stoi(req.get_header_value("Content-Length"));
    }
    catch(const std::exception& e)
    {
      return crow::response(500);
    }

    if(length < 0 || req.body.length() != (unsigned int)length)
    {
      return crow::response(500); //nice try
    }

    CROW_LOG_INFO << "err: " << req.body;
    return crow::response(200);
  });

  CROW_ROUTE(app, "/crow/echo")
  .methods("POST"_method, "GET"_method)
  ([](const crow::request& req)
  {
    std::string html;

    if(method_name(req.method) == "GET")
    {
      CROW_LOG_INFO << "echo GET request";
    }
    else
    { //no need for further cases; this route only takes GET and POST.
      CROW_LOG_INFO << "echo POST request";
    }

    //html = "<!DOCTYPE html><body><pre>\n";
    //html += "<!-- begin echo -->\n";

    for( auto const& data: req.headers)
    {
      html += data.first + ":" + data.second + "\n";
    }

    html += "url:" + req.raw_url +"\n";

    try
    {
      int length = std::stoi(req.get_header_value("Content-Length"));
      if(length > 0)
      {
        if((unsigned int)length == req.body.length())
        {
          html += "body:" + req.body + "\n";
        }
        else
        {
          html += "invalid request body length.\n";
        }
      }
      else
      {
        html += "zero length request body.\n";
      }
    }
    catch (const std::exception &e)
    {
      html += "no request body.\n";
    }

    //html += "<!-- end echo -->\n";
    //html += "</pre></body></html>\n";

    //uncomment above if response is needed to be formatted for html display.

    crow::response res(html);
    res.add_header("Content-Type", "text/html");
    return res;
  });

  app.port(40080)
  .multithreaded()
  .run();
}
