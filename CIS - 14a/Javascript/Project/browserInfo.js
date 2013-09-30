var username = GetCookie('username');

if (username == null) {
  username = prompt('Please enter your name (otherwise press cancel)',"WebSurfer");
  if (username == null) {
    alert('Its ok if you dont want to tell me your name');
    username = 'WebSurfer';
  } else {
    pathname = location.pathname;
    myDomain = pathname.substring(0,pathname.lastIndexOf('/')) +'/';
    var largeExpDate = new Date ();
    largeExpDate.setTime(largeExpDate.getTime() + (365 * 24 * 3600 * 1000));
    SetCookie('username',username,largeExpDate,myDomain);
  }
}

function getCookieVal (offset) {
  var endstr = document.cookie.indexOf (";", offset);
  if (endstr == -1)
  endstr = document.cookie.length;
  return unescape(document.cookie.substring(offset, endstr));
}

function GetCookie (name) {
  var arg = name + "=";
  var alen = arg.length;
  var clen = document.cookie.length;
  var i = 0;
  while (i < clen) {
    var j = i + alen;
    if (document.cookie.substring(i, j) == arg)
    return getCookieVal (j);
    i = document.cookie.indexOf(" ", i) + 1;
    if (i == 0)
    break;
  }
  return null;
}

function SetCookie (name, value) {
  var argv = SetCookie.arguments;
  var argc = SetCookie.arguments.length;
  var expires = (argc > 2) ? argv[2] : null;
  var path = (argc > 3) ? argv[3] : null;
  var domain = (argc > 4) ? argv[4] : null;
  var secure = (argc > 5) ? argv[5] : false;
  document.cookie = name + "=" + escape (value) +
    ((expires == null) ? "" : ("; expires=" +
    expires.toGMTString())) +
    ((path == null) ? "" : ("; path=" + path)) +
    ((domain == null) ? "" : ("; domain=" + domain)) +
    ((secure == true) ? "; secure" : "");
}
