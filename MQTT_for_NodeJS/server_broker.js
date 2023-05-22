const aedes = require('aedes')()
const server = require('net').createServer(aedes.handle)
const port = 1883

console.log('aedes :>> ', aedes);

server.listen(port, function() {
    console.log('server started and listening on port ', port)
});
server.addListener