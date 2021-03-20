"use strict";

//PWA and WebService
const exp = require("express");
const app = exp();
const pth = require("path");
app.listen(3100)


app.use("/app", exp.static(pth.join(__dirname, "", "/node_www/index.html")));
app.use("/jquery", exp.static(pth.join(__dirname, "", "/node_www/jquery.js")));
app.use("/script", exp.static(pth.join(__dirname, "", "/node_www/script.js")));
app.use("/style", exp.static(pth.join(__dirname, "", "/node_www/style.css")));

app.get("/api/:lamp/:state", (q, r) => {
    let lamp = q.params.lamp;
    let state = q.params.state;
    r.send("DONE " + lamp + " " + state);
});

//Arduino Communication Link