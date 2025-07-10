console.log("Hello");
function fetchdata(callback)
{
    setTimeout(()=>

{
callback();
}   ,2000 )
}
fetchdata(()=>
{
    console.log("Fetching done!!");
});
console.log("I am fethcing a data");
