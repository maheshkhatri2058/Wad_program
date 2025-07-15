// fetch('https://jsonplaceholder.typicode.com/posts/1')
//   .then(res => res.json())
//   .then(data => console.log(data))
//   .catch(err => console.error(err));
async function fetchdata()
{
let data=await fetch("https://jsonplaceholder.typicode.com/posts");
let newdata=await data.json();
console.log(newdata);
console.log(newdata.id);

console.log(newdata.body);
document.getElementById("fetchdata").innerHTML=newdata.body+newdata.title;
}
fetchdata();