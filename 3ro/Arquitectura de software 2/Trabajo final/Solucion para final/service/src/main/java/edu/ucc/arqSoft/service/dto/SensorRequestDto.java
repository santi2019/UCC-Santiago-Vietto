package edu.ucc.arqSoft.service.dto;

public class SensorRequestDto {
	
	private String location;
	
	private String status;

	public String getLocationName() {
		return location;
	}

	public void setLocationName(String location) {
		this.location = location;
	}

	public String getStatus() {
		return status;
	}

	public void setStatus(String status) {
		this.status = status;
	}
}	