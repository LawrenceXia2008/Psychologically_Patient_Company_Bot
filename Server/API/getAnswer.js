var client = require("./directLine v3");

var secret = "bZPwTlAikCE.cwA._X0.j9hdV69ovmgIQOzkhvDpQhOz6dL4AJEH7NZIGa106ac";
var _tokenObject = 0;
var _conversationWss;
var _watermark = 0;
var flag = 0;

var messageBody = {
  type: "message",
  from: {
    id: "user1"
  },
  text: "你好"
};
//console.log(global.expression_json);
function getTokenAndGetConverstation(){
  return new Promise( ( reslove , reject ) => {
    client.getTokenObject( secret ).subscribe(
      tokenObject => {
        _tokenObject = tokenObject;
        flag = 1;
        //create Conversation
        client.initConversationStream( _tokenObject ).subscribe(
          message => {
            _conversationWss = message;
            reslove();
          },
          err => {
            console.log( err );
            reject( "init CS Failed" + err.toString() );
          }
        )
      },
      err => {
        console.log( err );
        reject( "get Token Failed" + err.toString() );
      }
    )
  })
}

async function perpare(){
  await getTokenAndGetConverstation().catch( $ => perpare() );
};

perpare();

setInterval( () => {
  _tokenObject = 0;
  _conversationWss;
  _watermark = 0;
  flag = 0;
  perpare();
}, 26 * 60 * 1000 );//重置

// happy, content, unhappy
result = {
    '这里的医生护士人都超级专业超级好的~我相信只要你按照疗程继续治疗，过不了几天你就可以出院当上总经理，迎娶白富美，走上人生巅峰，飞起来和太阳肩并肩了！': [
        '亲爱的你今天看起来心情不错嘛，也就剩这几天了，还不快快珍惜和本大美女相处的时间？',
        '这里的医生护士人都超级专业超级好的~我相信只要你按照疗程继续治疗，过不了几天你就可以出院当上总经理，迎娶白富美，走上人生巅峰，飞起来和太阳肩并肩了！',
        '你看起来心情很糟糕呢，别这样，相信我，没有什么困难是一本一点点不能克服的，如果有那就是两杯！'],
    '没关系 只要你开口本美女就给你讲一个小故事~北京邮电大学是教育部直属、工业和信息化部共建、首批进行211工程建设的全国重点大学，是985优势学科创新平台项目重点建设高校，是首批双一流建设高校': [
        '看你今天好开心的样子哦！那我们一起看《西红柿首富》吧，听说沈腾在电影里超级搞笑呢',
        '没关系 只要你开口本美女就给你讲一个小故事~北京邮电大学是教育部直属、工业和信息化部共建、首批进行211工程建设的全国重点大学，是985优势学科创新平台项目重点建设高校，是首批双一流建设高校',
        '看起来你今天心情真的好难过哟，亲爱的你相信我现在下不了床只是暂时的，只要再过一些日子我们就可以一起欢快玩耍啦'],
    '你好啊朋友~康复的疗程虽然漫长~不过我会一直陪伴在你的身边的~想笑我就陪着你笑~想哭我就陪着你开心~想聊天你就随时找我哦~': [
        '你好你好，今天看起来状态不错，是不是想我了呢',
        '你好啊朋友~康复的疗程虽然漫长~不过我会一直陪伴在你的身边的~想笑我就陪着你笑~想哭我就陪着你开心~想聊天你就随时找我哦~',
        '你好，宝宝看起来今天你有些不开心呢，你可以把你的心事和我说一说嘛，我会认真听呢'],
    '怎么可能呢 每个人都有需要别人关心照顾的时候呢 哪天本大美女生了病 你也要照顾我哦': [
        '嘿嘿 看起来你今天心情不错，还和我开玩笑呢，哪里有人嫌弃你累赘，再这么说我可要惩罚你胸口碎大石，空手劈榴莲了！',
        '怎么可能呢，每个人都有需要别人关心照顾的时候呢，哪天本大美女生了病，你也要照顾我哦',
        '来抱抱~你一定是今天心情不是很好才会这么想的，大家都会一直关心你照顾你的，而且你也一直陪伴着我们呀，你不仅不拖累我们，而且有在你身边，我们一直都很开心呢']
}

function convert(origin, expression) {
	console.log(origin,expression);
    return (result[origin] || {[expression]: origin})[expression];
}
module.exports = ({ res , req }) => {
  console.log( "getAnswer api 收到：", req.body.text );
  client.sendMessage( _tokenObject , {
    type: "message",
    from: {
      id: "user1"
    },
    text: req.body.text
  } ).subscribe(
    data => {
      var id = data.id;
      client.getMessage( _tokenObject , _watermark ).subscribe(
        result => {
          console.log( "微软机器人回复:", result );
            _watermark = result.watermark;
            
             //here call a function 
			 
          result.activities[1].text = convert(result.activities[1].text, Number(global.expression_json));
          res.send( result );
        }
      )
   },
   err => console.log( err )
  )
}
