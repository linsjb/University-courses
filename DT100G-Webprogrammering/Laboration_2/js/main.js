/*
* Author: Linus Sjöbro
* Author email: lisj1502@student.miun.se
*/

// Create a request to the server with the provided url
function Get(url) {
  let request = new XMLHttpRequest();
  request.open('Get', 'http://api.arbetsformedlingen.se/af/v0' + url, false);
  request.send(null);

  if(request.status == 200) {
    return JSON.parse(request.responseText);
  } else if (request.status == 400) {
    console.log('Error 400');
  } else {
    console.log('Something else was returned');
  }
}

// List all applications (annonser) of the given url
function listOfApplications(data) {
  // Empty the parent element's content.
  // To avoid that the list is just getting longer and longer when a new area is selected.
  info.innerHTML = '';

  if(data.matchningslista.matchningdata.length == 0) {
    console.log('test');
    let noApplications = document.createElement('h1');
    noApplications.setAttribute('class', 'noAppTitle');
    noApplications.appendChild(document.createTextNode('Inga annonser funna'));
    info.appendChild(noApplications);
  } else {
    // Loop through the area's applications.
    for(let i = 0; i < data.matchningslista.matchningdata.length; i++) {
      // Get the applications data for the specific area
      let applicationsData = Get('/platsannonser/' + data.matchningslista.matchningdata[i].annonsid);

      // Get the application details
      let applicationDetails = applicationsData.platsannons.annons;

      // Get the application information
      let applicationInfo = applicationsData.platsannons.ansokan;

      // Create the HTML elements that's needed for the application cell
      let resultCellContainer = document.createElement('div');
      resultCellContainer.setAttribute('class', 'resultCell');

      let cellTitle = document.createElement('h1');
      cellTitle.appendChild(document.createTextNode(applicationDetails.annonsrubrik));
      cellTitle.setAttribute('class', 'cellTitle');

      let cellHireType = document.createElement('p');
      cellHireType.appendChild(document.createTextNode('Anställningstyp: ' + applicationDetails.anstallningstyp));
      cellHireType.setAttribute('class', 'cellHireType');

      let cellnumOfPlaces = document.createElement('p');
      cellnumOfPlaces.appendChild(document.createTextNode('Antal platser: ' + applicationDetails.antal_platser));
      cellnumOfPlaces.setAttribute('class', 'cellnumOfPlaces');

      let cellPubDate = document.createElement('p');
      cellPubDate.appendChild(document.createTextNode('Publiceringsdatum: ' + applicationDetails.publiceraddatum));
      cellPubDate.setAttribute('class', 'cellPubDate');

      let cellLastDate = document.createElement('p');
      cellLastDate.appendChild(document.createTextNode('Sista ansökningsdag: ' + applicationInfo.sista_ansokningsdag));
      cellLastDate.setAttribute('class', 'cellLastDate');

      let cellButton = document.createElement('a');
      cellButton.appendChild(document.createTextNode('Läs mer'));
      cellButton.setAttribute('class', 'btn');
      cellButton.setAttribute('href', applicationDetails.platsannonsUrl);

      resultCellContainer.appendChild(cellTitle);
      resultCellContainer.appendChild(cellHireType);
      resultCellContainer.appendChild(cellnumOfPlaces);
      resultCellContainer.appendChild(cellPubDate);
      resultCellContainer.appendChild(cellLastDate);
      resultCellContainer.appendChild(cellButton);

      info.appendChild(resultCellContainer);
    }
  }
}

// Get the data from the request with the provided data. The inserted data is the area id(länid).
function getData(data) {
  let keyword = document.getElementById('searchText').value;
  let numRows = document.getElementById('numrows').value;

  if(document.getElementById('onlyit').checked) {
    if(keyword == "") {
      return Get('/platsannonser/matchning?lanid=' + data + '&yrkesomradeid=3&antalrader=' + numRows);
    } else {
      return Get('/platsannonser/matchning?lanid=' + data + '&yrkesomradeid=3&antalrader=' + numRows + '&nyckelord=' + keyword);
    }
  } else {
    if(keyword == "") {
      return Get('/platsannonser/matchning?lanid=' + data + '&antalrader=' + numRows);
    } else {
      return Get('/platsannonser/matchning?lanid=' + data + '&antalrader=' + numRows + '&nyckelord=' + keyword);
    }
  }
}

// Wait for DOM to load
document.addEventListener("DOMContentLoaded", function(){
  let jsonData = Get('/platsannonser/soklista/lan/');

  for(var i = 0; i < jsonData.soklista.sokdata.length; i++) {
    document.getElementById("searchlan").innerHTML += "<option value='"+jsonData.soklista.sokdata[i].id+"'>"+jsonData.soklista.sokdata[i].namn+"</option>";
    document.getElementById("mainnavlist").innerHTML += "<li id='"+jsonData.soklista.sokdata[i].id+"'>"+jsonData.soklista.sokdata[i].namn+" (" + jsonData.soklista.sokdata[i].antal_ledigajobb + ")</li>";
  }
});

let info = document.getElementById('info');

document.getElementById('mainnavlist').addEventListener("click", (e) => {
  listOfApplications(getData(e.target.id));
});

document.getElementById('searchbutton').addEventListener('click', () => {
  listOfApplications(getData(searchlan.options[searchlan.selectedIndex].value));
});
