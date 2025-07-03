switch(1)
{
    case 1:
       console.log("Number is 1");
       break;
    case 2:
      console.log("Number is 2");
      break;
    default:
      console.log("Invalid option");
}
function h()
{
  console.log("Hello");
}
function greet(dun)
{
   console.log("gn call");
  dun();
}
greet(h);
function hello()
{
  return function hii()
  {
    console.log("Hello muj");
  }
}
console.log(hello());