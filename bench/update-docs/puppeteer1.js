const puppeteer = require('puppeteer');

const bench_images = [
"parse_apache_builds.png", 
"parse_canada.png",
"parse_citm_catalog.png",
"parse_github_events.png", 
"parse_gsoc_2018.png",
"parse_instruments.png",
"parse_marine_ik.png",
"parse_mesh.png",
"parse_mesh_pretty.png",
"parse_numbers.png",
"parse_random.png",
"parse_twitter.png",
"parse_twitterescaped.png",
"parse_update_center.png",
"serialize_apache_builds.png",
"serialize_canada.png",
"serialize_citm_catalog.png",
"serialize_github_events.png",
"serialize_gsoc_2018.png",
"serialize_instruments.png",
"serialize_marine_ik.png",
"serialize_mesh.png",
"serialize_mesh_pretty.png",
"serialize_numbers.png",
"serialize_random.png",
"serialize_twitter.png",
"serialize_twitterescaped.png",
"serialize_update_center.png"
];

(async () => {
  // const browser = await puppeteer.launch();
  const browser = await puppeteer.launch({ args: ['--no-sandbox', '--disable-setuid-sandbox'], });

  const page = await browser.newPage();
  await page.setViewport({
  width: 1000,
  height: 1000,
  deviceScaleFactor: 1,
  });
  await page.goto('http://localhost/results.html');
  await page.waitForTimeout(3000);

  let i = 0;
  let y_position = 128;
  while (i < bench_images.length) {
    imagename="tmp/" + bench_images[i]    
    await page.screenshot({ path: imagename , 'clip': {'x':0, 'y': y_position, 'width': 668, 'height': 375}});
    i++;
    y_position = y_position + 443.8;
  }
  await browser.close();
})();
