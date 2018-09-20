/**
*接收一个带参数的http请求
* 127.0.0.1:3000/http_get
* name=小小沉沉&password=qwer
*/

//导入http模块
var http=require('http');

//导入url模块
var url=require('url');
var log=require('./log4js_readconfig');
var querystring = require("querystring");

http.createServer(function(request,response){
    request.setEncoding('utf-8');

     var postData = "";
    // 数据块接收中
    request.on("data", function (postDataChunk) {
        postData += postDataChunk;
    });

    request.on("end", function () {
        console.log('数据接收完毕');
        var params = querystring.parse(postData);//GET & POST  ////解释表单数据部分{name="zzl",email="zzl@sina.com"}
        console.log(params);
        console.log(params["name"]+"~~"+params["password"]);

        response.writeHead(200,{'Content-Type':'text/html;charset=utf-8'});//设置response编码为utf-8
        response.write("======================================="+params["name"]+"~~"+params["age"]);
            response.write(util.inspect(params));
        response.end("数据提交完毕");
    });

}).listen(8081);
console.log("--HTTP NodeJS Connect--");