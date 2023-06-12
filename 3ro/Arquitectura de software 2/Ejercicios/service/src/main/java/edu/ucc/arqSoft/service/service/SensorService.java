package edu.ucc.arqSoft.service.service;

import java.util.ArrayList;
import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import edu.ucc.arqSoft.service.dao.SensorDao;
import edu.ucc.arqSoft.service.dto.SensorRequestDto;
import edu.ucc.arqSoft.service.dto.SensorResponseDto;
import edu.ucc.arqSoft.service.model.Location;
import edu.ucc.arqSoft.service.model.Sensor;

@Service
@Transactional
public class SensorService {

	@Autowired
	private SensorDao sensorDao;
	
	public List<SensorResponseDto> getSensorsByLocation(int ordinal) {
		List<Sensor> sensors = sensorDao.getAll();
		List<SensorResponseDto> dtos = new ArrayList<SensorResponseDto>();
		
		SensorResponseDto dto;
		
		Location location = Location.values()[ordinal];

		for (Sensor sensor : sensors) {
			dto = new SensorResponseDto();
			if (sensor.isStatus() && location == sensor.getLocation()) {
				dto.setStatus(sensor.isStatus());
				dto.setLocation(sensor.getLocation().toString().toLowerCase());
				dto.setId(sensor.getId());
				
				dtos.add(dto);
			}
		}
		
		return dtos;
		
	}

	public SensorResponseDto getSensorById(Long id) {

		Sensor sensor = sensorDao.load(id);

		SensorResponseDto dto = new SensorResponseDto();
		// verificar
		dto.setStatus(sensor.isStatus());
		dto.setLocation(sensor.getLocation().toString().toLowerCase());
		dto.setId(id);
		
		return dto;

	}

	public SensorResponseDto registrar(SensorRequestDto dto) {

		Sensor sensor = new Sensor();
		sensor.setStatus(dto.isStatus());
		sensor.setLocation(Location.values()[dto.getLocation()]);

		sensorDao.insert(sensor);
		
		SensorResponseDto response = new SensorResponseDto();
		response.setStatus(sensor.isStatus());
		response.setLocation(sensor.getLocation().toString().toLowerCase());
		response.setId(sensor.getId());
		
		return response;

	}

	public SensorResponseDto prender(Long id) {

		Sensor sensor = sensorDao.load(id);
		
		if (!sensor.isStatus()) {
			sensor.setStatus(true);
		}
		
		//get sensor by id
		sensorDao.update(sensor);
		
		SensorResponseDto response = new SensorResponseDto();
		response.setStatus(sensor.isStatus());
		response.setLocation(sensor.getLocation().toString().toLowerCase());
		response.setId(sensor.getId());

		return response;
	}

	public List<SensorResponseDto> getSensors() {

		List<Sensor> sensors = sensorDao.getAll();
		
		List<SensorResponseDto> dtos = new ArrayList<SensorResponseDto>();
		
		SensorResponseDto dto;
		for (Sensor sensor : sensors) {
			dto = new SensorResponseDto();
			dto.setStatus(sensor.isStatus());
			dto.setLocation(sensor.getLocation().toString().toLowerCase());
			dto.setId(sensor.getId());
			
			dtos.add(dto);
		}
		
		return dtos;
	}

	/*
    public void modificarSensor(@PathParam("ID") int id) {
    	Sensor nuevo = leerSensor(is);
  		Sensor actual = sensor.getId(ID);
   	 	if (actual == null){
			throw new WebApplicationException(Response.Status.NOT_FOUND);	
		}
    	actual.setStatus(nuevo.getStatus());
	}
	*/

}