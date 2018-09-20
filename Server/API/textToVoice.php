<?php
define('DEMO_CURL_VERBOSE', false);

$apiKey = "PWLuXQGtv395HlyvCg2rMCrj";

$secretKey = "cff397c6dd1f15a44880068260fb71d5";

$text = $argv[1];

$text2 = iconv("UTF-8", "GBK", $text);

#发音人选择, 0为普通女声，1为普通男生，3为情感合成-度逍遥，4为情感合成-度丫丫，默认为普通女声
$per = $argv[2];
#语速，取值0-9，默认为5中语速
$spd = 5;
#音调，取值0-9，默认为5中语调
$pit = 5;
#音量，取值0-9，默认为5中音量
$vol = 5;

$cuid = "123456PHP";

$auth_url = "https://openapi.baidu.com/oauth/2.0/token?grant_type=client_credentials&client_id=".$apiKey."&client_secret=".$secretKey;
$ch = curl_init();
curl_setopt($ch, CURLOPT_URL, $auth_url);
curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
curl_setopt($ch, CURLOPT_CONNECTTIMEOUT, 5);
curl_setopt($ch, CURLOPT_SSL_VERIFYPEER, false); //信任任何证书
curl_setopt($ch, CURLOPT_SSL_VERIFYHOST, 0); // 检查证书中是否设置域名,0不验证
curl_setopt($ch, CURLOPT_VERBOSE, DEMO_CURL_VERBOSE);
$res = curl_exec($ch);

curl_close($ch);

$response = json_decode($res, true);

if (!isset($response['access_token'])){
	exit(1);
}
if (!isset($response['scope'])){
	exit(2);
}

if (!in_array('audio_tts_post',explode(" ", $response['scope']))){
	exit(3);
}

$token = $response['access_token'];

$params = array(
	'tex' => $text,
	'per' => $per,
	'spd' => $spd,
	'pit' => $pit,
	'vol' => $vol,
	'cuid' => $cuid,
	'tok' => $token,
	'lan' => 'zh', //固定参数
	'ctp' => 1, // 固定参数
);

$url = 'http://tsn.baidu.com/text2audio?' . http_build_query($params);

$g_has_error = true;
$ch = curl_init();
curl_setopt($ch, CURLOPT_URL, $url);
curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
curl_setopt($ch, CURLOPT_CONNECTTIMEOUT, 5);

function read_header($ch, $header){
	global $g_has_error;

	$comps = explode(":", $header);
	// 正常返回的头部 Content-Type: audio/mp3
	// 有错误的如 Content-Type: application/json
	if (count($comps) >= 2){
		if (strcasecmp(trim($comps[0]), "Content-Type") == 0){
			if (strpos($comps[1], "mp3") > 0 ){
				$g_has_error = false;
			} else {
				#echo $header ." , has error \n";
			}
		}
	}
	return strlen($header);
}
curl_setopt($ch, CURLOPT_HEADERFUNCTION, 'read_header');
$data = curl_exec($ch);
if(curl_errno($ch))
{
	exit(2);
}
curl_close($ch);

$publicDir = realpath( __DIR__ . "/../../../public/" );

function generateRandomString($length = 10) {
    $characters = '0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ';
    $charactersLength = strlen($characters);
    $randomString = '';
    for ($i = 0; $i < $length; $i++) {
        $randomString .= $characters[rand(0, $charactersLength - 1)];
    }
    return $randomString;
}

$hash = generateRandomString( 128 );
$file = $g_has_error ? "result.txt" : $publicDir."/result".$hash.".mp3";

file_put_contents($file, $data);
echo "/result".$hash.".mp3";
