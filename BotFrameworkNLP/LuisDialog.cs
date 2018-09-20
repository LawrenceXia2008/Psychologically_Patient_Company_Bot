using Microsoft.Bot.Builder.Dialogs;
using Microsoft.Bot.Builder.Luis;
using Microsoft.Bot.Builder.Luis.Models;
using System;
using System.Text;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Web;
using Microsoft.Bot.Connector;
using System.Diagnostics;

namespace 聊天机器人
{
    
    [LuisModel("4d0758ec-685b-4a09-86fc-90a16c50e089", "14fce2759596410cbaa7e0371454f788")]
    [Serializable]
    public class LuisDialog : LuisDialog<object>
    {
      
        [LuisIntent("无事可做")]
        public async Task Bored(IDialogContext context, LuisResult result)
        {

                await context.PostAsync("没关系 只要你开口本美女就给你讲一个小故事~北京邮电大学是教育部直属、工业和信息化部共建、首批进行211工程建设的全国重点大学，是985优势学科创新平台项目重点建设高校，是首批双一流建设高校");
                context.Wait(MessageReceived);
                //List<string> ls = new List<string>();
                //ls.AddRange( System.IO.Directory.GetDirectories("."));
        }
        [LuisIntent("还有几天出院")]
        public async Task OffHospital(IDialogContext context, LuisResult result)
        {
            await context.PostAsync("这里的医生护士人都超级专业超级好的~我相信只要你按照疗程继续治疗，过不了几天你就可以出院当上总经理，迎娶白富美，走上人生巅峰，飞起来和太阳肩并肩了！");
            context.Wait(MessageReceived);
        }
        [LuisIntent("打招呼")]
        public async Task Greeting(IDialogContext context, LuisResult result)
        {
            await context.PostAsync("你好啊朋友~康复的疗程虽然漫长~不过我会一直陪伴在你的身边的~想笑我就陪着你笑~想哭我就陪着你开心~想聊天你就随时找我哦~");
            context.Wait(MessageReceived);
        }
        [LuisIntent("嫌弃累赘")]
        public async Task BeingDisgusted(IDialogContext context, LuisResult result)
        {
            await context.PostAsync("怎么可能呢 每个人都有需要别人关心照顾的时候呢 哪天本大美女生了病 你也要照顾我哦");
            context.Wait(MessageReceived);
        }
        [LuisIntent("")]
        public async Task none(IDialogContext context, LuisResult result)
        {
            await context.PostAsync("嗯嗯我懂得啦~今天也是元气满满的一天呢");
            context.Wait(MessageReceived);
        }
    }
}