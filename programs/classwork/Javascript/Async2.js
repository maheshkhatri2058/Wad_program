function fetchdata(success)
{
    return new Promise((resolve,reject)=>
    {
        setTimeout(() => {
            if(success){
            resolve("Data fetched successfuly");

        }
        else
        {
            reject("Failed");
        }
            
        }, 3000);
    });
}
fetchdata(true).then(result=>{
console.log(result);
}).catch(error=>
{
    console.log(error)
}
)
