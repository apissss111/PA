async function lihatBooth() {

    const response = await fetch("http://localhost:8080/admin/booth");

    const data = await response.json();

    let hasil = "";

    data.forEach(booth => {

        hasil += `
            <div>
                <h3>${booth.namaBooth}</h3>
                <p>Lokasi : ${booth.lokasi}</p>
                <p>Harga : ${booth.harga}</p>
            </div>
        `;
    });

    document.getElementById("hasil").innerHTML = hasil;
}