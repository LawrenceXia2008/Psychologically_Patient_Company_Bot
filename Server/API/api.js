module.exports = ({ req, res }) => {
    global.expression_json = req.body;
    res.send('hello');
	console.log(req.body);
}
