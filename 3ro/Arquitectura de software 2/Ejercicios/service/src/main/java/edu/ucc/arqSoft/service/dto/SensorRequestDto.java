package edu.ucc.arqSoft.service.dto;

public class SensorRequestDto {
	
	//TITULO, SINOPSIS, ANIO, GENERO
	
	private int location;
	
	private boolean status;

	public int getLocation() {
		return location;
	}

	public void setLocation(int location) {
		this.location = location;
	}

	public boolean isStatus() {
		return status;
	}

	public void setStatus(boolean status) {
		this.status = status;
	}
}	