'use strict'

const mqtt = require("mqtt")

const client = mqtt.connect("mqtt://127.0.0.1:1883");

client.on("connect", ack => {
    console.log("connected!");
    console.log(ack);

    client.subscribe("esp/001/001", err => {
        console.log(err);
    });

    client.on("message", (topic, message) => {
        console.log(topic);
        // message is Buffer
        console.log(message.toString());
    });
});

client.on("error", err => {
    console.log(err);
});