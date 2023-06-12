package edu.ucc.arqSoft.service.dto;

import java.util.Date;

public class PeliculaResponseDto {
	
	private String nombre;
	
	private String genero;
	
	private Long id;
	
	// ------
	
	
	public String getNombre() {
		return nombre;
	}

	public Long getId() {
		return id;
	}

	public void setId(Long id) {
		this.id = id;
	}

	public void setNombre(String nombre) {
		this.nombre = nombre;
	}

	public String getGenero() {
		return genero;
	}

	public void setGenero(String genero) {
		this.genero = genero;
	}
}
