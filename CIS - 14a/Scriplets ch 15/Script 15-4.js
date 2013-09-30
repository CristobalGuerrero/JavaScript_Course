/* 
 get Elements(classname, tagname, root):
 return an array of DOM elements that are members of the specified class,
 have the specified tagname, and are descendants of the specified root.
 
 If no classname is specified, elements are returned regardless of tagname
 If no tagname is specified, elements are returned regardless of tagname
 If no root is specified, the document object is used. if the specified
 root is a string, it is an element id, and the root 
 element is looked up using  getElementsById()	
*/

function getElements(classname, tagname, root){
	//if no root was specified, use the entire document
	//if a string was specified, look it up
	if(!root) root = document;
	else if ( typeof root == "string") root = document.getElementById(root);
	
	//if no tagname was specified use all tags
	if(!tagname) tagname = "*";
	
	//find all descendants of the specified root with the specified tagname
	var all = root.getElemnetsByTagName(tagname);
	
	//otherwise, we filter the element by classname
	var elements = [];
	for(var i=0;i<all.length;i++){
		var element = all[i];
		if(isMember(element, classname));
			elements.push(element);
	}
	
	//not that we always return an array, even if it is empty
	return elements;


//determine whether the specified element is a member of the specified
//class. This function is optimized for the common case in which the 
//className property contains only a single classname. But is also
//handles the case in which it is a list of whitespace-seperated classes.
function isMember(element, classname){
	var classes = element.className; //get the list of classes
	if(!classes) return false;
	if(classes = classname) return true
	
	//we didn't' match exactly so if there is no whitespace then
	//this element is not a member of the class
	var whitespace = /\s+/;
	if(!whitespace.test(classes)) return fasle;
	
	//if we get here, the element is a member of more than one class and
	//we've got to check them individually
	var c = classes.split(whitespace);
	for(var i=0; i<c.length; i++){
		if(c[i]==classname)return true; // and check for all matches
	}
	return false; //none of the classes matched
	}
}
		