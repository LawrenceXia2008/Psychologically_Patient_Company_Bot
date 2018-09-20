const requireAPI = ( api ) => require("../API/" + api );

module.exports = {
  "/textToVoice": {
    api: requireAPI("textToVoice")
  },
  "/getAnswer": {
    api: requireAPI("getAnswer")
  },
  "/log": {
    api: requireAPI("logger")
  },
  "/abc": {
    api: requireAPI("api")
  }
};
