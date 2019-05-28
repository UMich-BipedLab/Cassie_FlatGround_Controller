// Copyright 2016 The MathWorks, Inc.

window.addEventListener("load", function load(e) {
    parent.postMessage(document.body.innerHTML, '*');
    window.removeEventListener("load", load, false);
});
