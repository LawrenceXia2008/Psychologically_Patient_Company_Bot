const path = require("path");
var execSync = require('child_process').execSync;

const phpFile = path.resolve( __dirname, "./textToVoice.php" );
const cache = {};

module.exports = ({ req, res }) => {
  const { text, voice } = req.body;
  if( cache[text] ){
    res.send({
      url: cache[text]
    });
  } else {
    stdout = execSync(`php "${phpFile}" "${text}" ${voice}`);
    cache[text] = stdout.toString();
    res.send({
      url: stdout.toString()
    });
  }
  console.log("已回复语音");
}
