(this["webpackJsonpreact-complete-guide"]=this["webpackJsonpreact-complete-guide"]||[]).push([[0],[,,,,,function(e,t,n){e.exports={"home-screen":"HomeScreen_home-screen__27yrC"}},function(e,t,n){e.exports={warning:"Warning_warning__30Quq"}},function(e,t,n){e.exports={"city-info":"CityInfo_city-info__3lIRW"}},function(e,t,n){e.exports={container:"Container_container__xoG1k"}},,,,,function(e,t,n){},,function(e,t,n){"use strict";n.r(t);var c=n(4),a=n.n(c),r=(n(13),n(2)),s=n(1),i=n(5),o=n.n(i),j=n(6),l=n.n(j),d=n(0),u=function(){return Object(d.jsx)("div",{className:l.a.warning,children:Object(d.jsx)("p",{children:"Oops! Seems like you have entered a wrong city name!"})})},b=function(e){return Object(d.jsxs)("div",{className:o.a["home-screen"],children:[e.isNameValid?"":Object(d.jsx)(u,{}),Object(d.jsxs)("h1",{children:["Air IQ  ",Object(d.jsx)("i",{class:"fas fa-fan"})]}),Object(d.jsxs)("form",{onSubmit:e.cityNameHandler,children:[Object(d.jsx)("input",{type:"text",placeholder:"Enter A City Name"}),Object(d.jsx)("button",{type:"submit",children:Object(d.jsx)("i",{class:"fas fa-search"})})]})]})},h=n(7),x=n.n(h),O=function(e){var t,n=e.data,c=n.data[0].aqi,a="";return c>0&&c<=50?(a="Good",t="green"):c>50&&c<=100?(a="Moderate",t="yellow"):c>100&&c<=150?(a="Unhealthy For Sensitive Groups",t="orange"):c>150&&c<=200?(a="Unhealthy",t="red"):c>200&&c<=250?(a="Very Unhealthy",t="purple"):(a="Hazardous",t="maroon"),Object(d.jsxs)("div",{className:x.a["city-info"],children:[Object(d.jsx)("h1",{children:"Air IQ"}),Object(d.jsx)("p",{children:"".concat(n.city_name,",").concat(n.country_code)}),Object(d.jsxs)("p",{children:["Air Quality Index: ","".concat(c)]}),Object(d.jsxs)("p",{children:[Object(d.jsx)("i",{class:"fas fa-circle",style:{color:"".concat(t)}}),"  This AQI is ",a]}),Object(d.jsx)("button",{onClick:e.onBack,children:"BACK"})]})},f=n(8),p=n.n(f),y=function(){var e=Object(s.useState)({}),t=Object(r.a)(e,2),n=t[0],c=t[1],a=Object(s.useState)(""),i=Object(r.a)(a,2),o=i[0],j=i[1],l=Object(s.useState)(!0),u=Object(r.a)(l,2),h=u[0],x=u[1];return Object(d.jsx)("div",{className:p.a.container,children:o?Object(d.jsx)(O,{data:n,onBack:function(){j("")}}):Object(d.jsx)(b,{cityNameHandler:function(e){e.preventDefault();var t=new XMLHttpRequest;t.addEventListener("readystatechange",(function(){4===t.readyState&&200===t.status?(c(JSON.parse(t.responseText)),j(e.target[0].value),x(!0)):4===t.readyState&&200!==t.status&&x(!1)})),t.open("GET","https://api.weatherbit.io/v2.0/current/airquality?city=".concat(e.target[0].value,"&key=02d24335c3704059a69d9f22faf97a92")),t.send()},isNameValid:h})})};var m=function(){return console.log(y),Object(d.jsx)("div",{children:Object(d.jsx)(y,{})})};a.a.render(Object(d.jsx)(m,{}),document.getElementById("root"))}],[[15,1,2]]]);
//# sourceMappingURL=main.e617f7ff.chunk.js.map